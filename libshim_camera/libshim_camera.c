/*
 * Copyright (C) 2015 The Android Open Source Project
 * Written by Dmitry Grinberg, adapted by LuK1337
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <utils/Log.h>
#include <hardware/power.h>
#include <hardware/hardware.h>

  extern void _ZN7android7String8C1EPKc(void **str8P, const char *str);
  
  extern void _ZN7android7String8D1Ev(void **str8P);
  
  extern void _ZN7android15GNCameraFeature15setPictureFrameEPc(void const);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface19gnUpdatePreviewSizeEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface20gnUpdatePictureFrameEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface23gnUpdateGestureShotModeEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface24gnUpdateGestureDetectionEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface14gnUpdateMirrorEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface15gnSetFaceBeautyEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface22gnUpdateSceneDetectionEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface21gnUpdateNightShotModeEv(void);
  
  extern void _ZN7qcamera25QCamera2HardwareInterface18gnUpdateLiveEffectEv(void);
  
void _ZN7qcamera25QCamera2HardwareInterface20gnUpdatePictureFrameEv(void)
{
    void *;

    _ZNK7android16CameraParameters6getStrEPKc(&const, char);
    _ZN7android15GNCameraFeature15setPictureFrameEPc(char);
}

void _ZN7qcamera25QCamera2HardwareInterface25gnUpdateFeatureParametersEv(void)
{
    void *;

    _ZN7qcamera25QCamera2HardwareInterface19gnUpdatePreviewSizeEv();
    _ZN7qcamera25QCamera2HardwareInterface20gnUpdatePictureFrameEv();
    _ZN7qcamera25QCamera2HardwareInterface23gnUpdateGestureShotModeEv();
    _ZN7qcamera25QCamera2HardwareInterface24gnUpdateGestureDetectionEv();
    _ZN7qcamera25QCamera2HardwareInterface14gnUpdateMirrorEv();
    _ZN7qcamera25QCamera2HardwareInterface15gnSetFaceBeautyEv();
    _ZN7qcamera25QCamera2HardwareInterface22gnUpdateSceneDetectionEv();
    _ZN7qcamera25QCamera2HardwareInterface21gnUpdateNightShotModeEv();
    _ZN7qcamera25QCamera2HardwareInterface18gnUpdateLiveEffectEv();
}

void _ZN7qcamera25QCamera2HardwareInterface16updateParametersEPKcRb()
{
    void *string;

    _ZN7android7String8C1EPKc(&string, "camera.msm8974");
    _ZN7qcamera18GNCameraParametersC2ERKN7android7String8E(&string);
    _ZN7qcamera18GNCameraParameters16updateParametersERS0_Rb();
    _ZN7qcamera17QCameraParameters21setBurstLEDFlashLevelE25cam_led_flash_burst_level();
    _ZN7qcamera25QCamera2HardwareInterface25gnUpdateFeatureParametersEv();
    _ZN7qcamera14QCameraChannel27UpdateStreamBasedParametersERNS_17QCameraParametersE();
    _ZN7qcamera18GNCameraParametersD2Ev();
    _ZN7android7String8D1Ev(&string);
}

void _ZN7qcamera19QCameraStateMachine26procEvtPreviewStoppedStateENS_21qcamera_sm_evt_enum_tEPv() {}
void _ZN7qcamera19QCameraStateMachine16smEvtProcRoutineEPv() {}
void _ZNK7android16CameraParameters6getStrEPKc() {}
