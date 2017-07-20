/**
  *  @Desctiption:
  *      Define and implement parameters for Gionee features.
  *
  *	@Author : wutz
  *	@Date    : 2013-09-24
  *	@Email   : wutz@gionee.com
  *	@Version: 1.0 
  */

#ifndef ANDROID_HARDWARE_QCAMERA_GNPARAMETERS_H
#define ANDROID_HARDWARE_QCAMERA_GNPARAMETERS_H

#ifndef ORIGINAL_VERSION

#include <QCameraParameters.h>
#include <cutils/properties.h>
#include <hardware/camera.h>
#include <stdlib.h>
#include <utils/Errors.h>
#include "cam_intf.h"

using namespace android;

namespace qcamera {

class GNCameraParameters: public QCameraParameters
{
public:
	GNCameraParameters();
    GNCameraParameters(const String8 &params);
    ~GNCameraParameters();

	//Picture frame
	static const char KEY_PICTURE_FRAME[];
	static const char KEY_PICTURE_FRAME_SUPPORTED[];
	static const char PICTURE_FRAME_NORMAL[];

	// Gesture shot mode
	static const char KEY_GESTURE_SUPPORTED[];
	static const char KEY_GESTURE_MODE[];
	static const char GESTURE_MODE_ON[];
	static const char GESTURE_MODE_OFF[];

	//Face beauty mode
    static const char KEY_FACE_BEAUTY_MODE[];
    static const char KEY_SUPPOTED_FACE_BEAUTY_MODE[];
	static const char KEY_FACE_BEAUTY_LEVEL[];
	static const char KEY_SLENDER_FACE_LEVEL[];
	static const char KEY_SKIN_SOFTEN_LEVEL[];
	static const char KEY_EYE_ENLARGMENT_LEVEL[];
    static const char FACE_BEAUTY_ON[];
    static const char FACE_BEAUTY_OFF[];    

	static const char KEY_FACE_BEAUTY_SUB_MODE[];
	static const char FACE_BEAUTY_AGEGENDER_MODE[];
	static const char FACE_BEAUTY_DEFAULT_MODE[];
	static const char KEY_FACE_BEAUTY_AGEGENDER_LEVEL[];

	//ageGender-detection
	static const char KEY_AGEGENDER_DETECTION_MODE[];
	static const char KEY_SUPPOTED_AGEGENDER_DETECTION_MODE[];
	static const char AGEGENDER_DETECTION_ON[];
	static const char AGEGENDER_DETECTION_OFF[];

	//PicZoom mode
	static const char KEY_PICZOOM_MODE[];
	static const char PICZOOM_MODE_ON[];
	static const char PICZOOM_MODE_OFF[];
	
	//Mirror mode
	static const char KEY_MIRROR_MODE[];
	static const char KEY_SUPPOTED_MIRROR_MODE[];
	static const char MIRROR_MODE_ON[];
	static const char MIRROR_MODE_OFF[];	

	// Gesture event type
	static const char KEY_GESTURE_EVENT_SUPPORTED[];
	static const char KEY_GESTURE_EVENT_TYPE[];
	static const char GESTURE_EVENT_NONE[];
	static const char GESTURE_EVENT_OPEN_HAND_PRESENCE[];
	static const char GESTURE_EVENT_FIST_PRESENCE[];
	static const char GESTURE_EVENT_FACE_PRESENCE[];

	//Scene detection mode
	static const char KEY_SCENE_DETECTION_MODE[];
	static const char KEY_SUPPOTED_SCENE_DETECTION_MODE[];
	static const char SCENE_DETECTION_ON[];
	static const char SCENE_DETECTION_OFF[];

	// Capture mode
	static const char KEY_CAPTURE_MODE[]; 
	static const char KEY_SUPPORTED_CAPTURE_MODES[];
	static const char CAPTURE_MODE_NORMAL[];
	static const char CAPTURE_MODE_BURST_SHOT[];
	static const char CAPTURE_MODE_NIGHTSHOT_SHOT[];
	static const char CAPTURE_MODE_PICZOOM_SHOT[];

	static const char KEY_BURST_SHOT_NUM[];

	// Live effect
	static const char KEY_LIVE_EFFECT[];
	static const char KEY_SUPPORTED_LIVE_EFFECTS[];
	static const char LIVE_EFFECT_NONE[];
	static const char LIVE_EFFECT_ANTIQUE[];
	static const char LIVE_EFFECT_CARTOON[];
	static const char LIVE_EFFECT_EMBOSS[];
	static const char LIVE_EFFECT_FLIP[];
	static const char LIVE_EFFECT_FOG[];
	static const char LIVE_EFFECT_GRAYSCALE[];
	static const char LIVE_EFFECT_LOMO_BLUE[];
	static const char LIVE_EFFECT_LOMO_GREEN[];
	static const char LIVE_EFFECT_LOMO_NEUTRAL[];
	static const char LIVE_EFFECT_LOMO_RED[];
	static const char LIVE_EFFECT_LOMO_YELLOW[];
	static const char LIVE_EFFECT_MAGICPEN[];
	static const char LIVE_EFFECT_MILKY[];
	static const char LIVE_EFFECT_MIRROR[];
	static const char LIVE_EFFECT_NEGATIVE[];
	static const char LIVE_EFFECT_OILY[];
	static const char LIVE_EFFECT_PAINT[];
	static const char LIVE_EFFECT_SEPIA[];
	static const char LIVE_EFFECT_SKETCH_COLOR[];
	static const char LIVE_EFFECT_SKETCH_GRAY[];
	static const char LIVE_EFFECT_SOLARIZE[];
	static const char LIVE_EFFECT_STAMP[];
	static const char LIVE_EFFECT_DOF[];
	static const char LIVE_EFFECT_VIGNETTING[];
	static const char LIVE_EFFECT_WARP_FISHEYE[];
	static const char LIVE_EFFECT_WARP_ALIENSCUM[];
	static const char LIVE_EFFECT_WARP_BIGBUPPA[];
	static const char LIVE_EFFECT_WARP_BOOZIEBOWL[];
	static const char LIVE_EFFECT_WARP_CONEHEAD[];
	static const char LIVE_EFFECT_WARP_FUNKYFRESH[];
	static const char LIVE_EFFECT_WARP_JELLYBELLY[];
	static const char LIVE_EFFECT_WARP_PETTYPETIT[];
	static const char LIVE_EFFECT_WARP_EYEBALLEDEVY[];
	static const char LIVE_EFFECT_WARP_SPEEDYWEED[];
	static const char LIVE_EFFECT_MOSAIC[];
	static const char LIVE_EFFECT_FROST[];
	static const char LIVE_EFFECT_MOON_LIGHT[];
	static const char LIVE_EFFECT_NOISE[];
	static const char LIVE_EFFECT_WATER_COLOR[];
	static const char LIVE_EFFECT_FLEETINGTIME[];
	static const char LIVE_EFFECT_CRAYON[];
	static const char LIVE_EFFECT_SNOWFLAKES[];
	static const char LIVE_EFFECT_LIGHTBEAM[];
	static const char LIVE_EFFECT_REFLECTION[];
	static const char LIVE_EFFECT_SUNSET[];
	static const char LIVE_EFFECT_REVERSAL[];
	static const char LIVE_EFFECT_WARMLOMO[];
	static const char LIVE_EFFECT_COLDLOMO[];
	static const char LIVE_EFFECT_SOFTPINK[];
	static const char LIVE_EFFECT_JAPANBACKLIGHT[];
	static const char LIVE_EFFECT_COSMETOLOGY_BACKLIGHT[];
	static const char LIVE_EFFECT_FINEFOOD[];
	static const char LIVE_EFFECT_BLACKWHITET[];

	int32_t init(cam_capability_t *, mm_camera_vtbl_t *, QCameraAdjustFPS *, QCameraTorchInterface *);
    int32_t updateParameters(GNCameraParameters&, bool &needRestart);
	int32_t setCaptureMode(const char *capMode);
	bool 	isContinuousShotMode() {return (m_nCaptureMode == CAM_CAPTURE_MODE_BURST);};
	bool 	isBurstNumInfinite() {return (m_nBurstNum <= 0);};
	int32_t getBurstShotNum() {return m_nBurstNum;};
	int32_t getNumOfExtraNightShotInBufsIfNeeded();
	int32_t getNumOfExtraNightShotOutBufsIfNeeded();
	int32_t getNumOfExtraNightShotBurst();
	int32_t getLiveEffect() {return m_nLiveEffect;};
	

private:
	int32_t setDefaultParameters();
	int32_t setCaptureMode(GNCameraParameters&);
	int32_t setFaceBeautyMode(const GNCameraParameters&);
	int32_t setAgeGenderDetectionMode(const GNCameraParameters&);
	int32_t setMirrorMode(const GNCameraParameters&);
	int32_t setGestureShotMode(const GNCameraParameters&);
	int32_t setGestureDetectionType(const GNCameraParameters&);
	int32_t setSceneDetection(const GNCameraParameters&);
	int32_t setPictureFrame(const GNCameraParameters&);
	int32_t setLiveEffect(const GNCameraParameters&);
	int32_t setPicZoomMode(const GNCameraParameters&);

    int 	lookupAttr(const QCameraMap arr[], int len, const char *name);
	String8 createValuesStringFromMap(const QCameraMap *map, int map_len);

    // Map from strings to values
	static const QCameraMap CAPTURE_MODES_MAP[];
	static const QCameraMap GESTURE_MODES_MAP[];
	static const QCameraMap FACE_BEAUTY_MODES_MAP[];
	static const QCameraMap AGEGENDER_DETECTION_MODES_MAP[];
	static const QCameraMap KEY_PICZOOM_MODES_MAP[];
	static const QCameraMap MIRROR_MODES_MAP[];
	static const QCameraMap GESTURE_EVENT_TYPES_MAP[];
	static const QCameraMap SCENE_DETECTION_MODES_MAP[];
	static const QCameraMap LIVE_EFFECTS_MAP[];
    
	bool m_bFaceBeautyMode;
	bool m_bAgeGenderDetectionMode;
	int32_t m_nBurstNum;
	int32_t m_nCaptureMode;
	int32_t m_nLiveEffect;
	
};

}; // namespace qcamera

#endif //ORIGINAL_VERSION
#endif //ANDROID_HARDWARE_QCAMERA_GNPARAMETERS_H
