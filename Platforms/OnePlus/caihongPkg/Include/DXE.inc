  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

  INF Binaries/caihong/QcomPkg/Drivers/EnvDxe/EnvDxeEnhanced.inf

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf

  INF Binaries/caihong/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF Binaries/caihong/QcomPkg/Drivers/TzDxe/ScmDxeCompat.inf
  INF Binaries/caihong/QcomPkg/Drivers/TzDxe/TzDxeLA.inf

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

  INF Binaries/caihong/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf

  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf

  INF Binaries/caihong/MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF Binaries/caihong/MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf

  INF FatPkg/EnhancedFatDxe/Fat.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

  INF Binaries/caihong/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/SmemDxe/SmemDxe.inf

  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

  INF Binaries/caihong/QcomPkg/Drivers/RscDxe/RscDxe.inf

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF Binaries/caihong/QcomPkg/Drivers/CPRDxe/CPRDxe.inf
!endif
  INF Binaries/caihong/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf

!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF Binaries/caihong/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
  # Re-enable (power-cycle) the panel after DXE display resets.
  # Same pattern used by enchilada / miatoll / equuleus / lavender.
  INF QcomPkg/Drivers/DisplayReEnablerDxe/DisplayReEnablerDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif

  INF Binaries/caihong/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/Smp2pDxe/Smp2pDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/SSRDxe/SSRDxe.inf
  # Crashes
  # INF Binaries/caihong/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/OcdtDxe/OplusProject.inf
  INF Binaries/caihong/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF Binaries/caihong/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/XhciDxe/XhciDxe.inf

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  INF Binaries/caihong/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/RNGDxe/RngDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF Binaries/caihong/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
