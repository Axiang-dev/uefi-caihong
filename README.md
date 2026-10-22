# uefi-caihong

OnePlus Pad Pro（`caihong` / OPD2404 / 高通 SM8650）的 UEFI 固件，基于
[Mu-Silicium](https://github.com/Project-Silicium/Mu-Silicium)。

**状态：可以正常进 BDS 启动菜单**（`Internal Storage` / `USB Storage` / `PXE Path` /
`Ram Storage` / `Power Off` / `Exit`），音量键上下移动、电源键确认。

> ⚠️ 开机时**必须按一次键**才会进菜单。不按键的话 BDS 找不到可启动项，
> 会走「无法启动」分支：画 logo → 停 10 秒 → 关机复位 → ABL 弹
> `Failed to find an operating system`。那句报错来自 ABL，不是本固件。

## 快速开始

```bash
adb reboot bootloader
fastboot boot Mu-caihong-0.img      # 全程内存运行，不写任何分区
```

## 自己编译

### GitHub Actions（推荐，无需本地环境）

推到 GitHub 后 `build` workflow 会自动跑，产物在 Actions 的 artifact 里；
打 `v*` tag 会自动发 Release。

### 本地 Linux / macOS

```bash
sudo apt install build-essential python3-venv clang llvm lld uuid-dev nasm \
                 gcc-aarch64-linux-gnu acpica-tools device-tree-compiler
./scripts/build.sh .work RELEASE     # 或 DEBUG
```

### 本地 Windows

Windows 上有两个额外的坑（`reg.exe` 被安全策略拦截、EDK2 报告器 GBK 崩溃），
用 `tools/pyfix` 绕过：

```bash
export PATH="/c/Program Files/LLVM/bin:$PATH"
export PYTHONIOENCODING=cp936 PYTHONUTF8=0
export PYTHONPATH='<repo>/tools/pyfix'
python build_uefi.py -d caihong -r RELEASE
```

细节见 [`docs/HANDOFF.md`](docs/HANDOFF.md) §3.5。

## 仓库结构

```
Platforms/OnePlus/caihongPkg/   设备包（DSC / FDF / DeviceBuild.py / 板级库）
Resources/Configs/caihong.toml  设备配置（FD 基址、boot image 头部版本）
Resources/DTBs/caihong.dtb      设备树（从原厂固件提取）
Binaries/caihong/               原厂 UEFI 驱动 + *.patched.efi（9 个补丁）
patches/                        构建用补丁（build_uefi.py / EDK2 报告器）
tools/                          二进制补丁重建、DEBUG 打包、Windows 构建修复
docs/HANDOFF.md                 完整交接文档（踩过的坑、排错记录、下一步）
scripts/build.sh                从零构建
```

`Binaries/caihong` 里的驱动是从本机固件提取的原厂二进制，`*.patched.efi`
由 `tools/apply_binary_patches.py` 从原厂文件按固定偏移生成，可随时重建。

## 九个二进制补丁

| 驱动 | 作用 |
|---|---|
| `VcsDxe` / `RscDxe` | 入口整体打桩（关屏元凶 / 让 DXE 派发走完） |
| `ClockDxe` ×2 | 跳过 `DCDDisableDependencies` |
| `SPMIDxe` | 防启动崩溃 |
| `PmicDxeLa` ×2 | SPMI 失败函数、假电池检测返回 SUCCESS |
| `UFSDxe` | Sleep → Wakeup（认内部存储） |
| `ButtonsDxe` ×2 | 电源键映射 ENTER |
| `UsbConfigDxe` ×2 | ExitBootServices 不 deinit USB |
| `UsbMsdDxe` | 改成非可移除 |

偏移表见 `tools/apply_binary_patches.py` 与 `docs/HANDOFF.md` §7。

## 下一步

在 UEFI 上启动 [UniXNU](https://unixnu.com)，最终跑 iOS / macOS。
设备仓库：`UniXNU-caihong`（板级配置与集成配方另行维护）。

## 声明

`Binaries/` 内的二进制来自设备原厂固件，版权归原厂所有，仅用于本机移植研究。
刷机有风险，`fastboot boot` 不写分区，但请自行评估。
