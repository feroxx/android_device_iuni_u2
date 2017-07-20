/**
  *  @Desctiption:
  *      Define and implement parameters for Gionee features.
  *
  *	@Author : wutz
  *	@Date    : 2013-09-24
  *	@Email   : wutz@gionee.com
  *	@Version: 1.0 
  */

#ifndef ORIGINAL_VERSION
  
#define LOG_TAG "GNCameraParameters"

#include <cutils/properties.h>
#include <math.h>
#include <utils/Errors.h>
#include <string.h>
#include <stdlib.h>
#include <gralloc_priv.h>

#include "GNCameraParameters.h"
#include "QCamera2HWI.h"

namespace qcamera {

//Picture frame
const char GNCameraParameters::KEY_PICTURE_FRAME[] 					= "picture-frame";
const char GNCameraParameters::KEY_PICTURE_FRAME_SUPPORTED[] 		= "picture-frame-supported";
const char GNCameraParameters::PICTURE_FRAME_NORMAL[] 				= "normal";

// Gesture shot mode
const char GNCameraParameters::KEY_GESTURE_SUPPORTED[] 				= "gesture-supported";
const char GNCameraParameters::KEY_GESTURE_MODE[] 					= "gesture";
const char GNCameraParameters::GESTURE_MODE_ON[] 					= "on";
const char GNCameraParameters::GESTURE_MODE_OFF[] 					= "off";

//Face beauty mode
const char GNCameraParameters::KEY_FACE_BEAUTY_MODE[] 				= "face-beauty-mode";
const char GNCameraParameters::KEY_SUPPOTED_FACE_BEAUTY_MODE[] 		= "face-beauty-mode-supported";
const char GNCameraParameters::KEY_FACE_BEAUTY_LEVEL[]				= "face-beauty-level";
const char GNCameraParameters::KEY_SLENDER_FACE_LEVEL[]				= "slender-face-level";
const char GNCameraParameters::KEY_SKIN_SOFTEN_LEVEL[]				= "skin-soften-level";
const char GNCameraParameters::KEY_EYE_ENLARGMENT_LEVEL[]			= "eye-enlargment-level";
const char GNCameraParameters::FACE_BEAUTY_ON[] 					= "on";
const char GNCameraParameters::FACE_BEAUTY_OFF[] 					= "off";   

const char GNCameraParameters::KEY_FACE_BEAUTY_SUB_MODE[]			= "face-beauty-sub-mode";
const char GNCameraParameters::KEY_FACE_BEAUTY_AGEGENDER_LEVEL[]	= "face-beauty-agegender-level";
const char GNCameraParameters::FACE_BEAUTY_AGEGENDER_MODE[]			= "face-beauty-agegender-mode";
const char GNCameraParameters::FACE_BEAUTY_DEFAULT_MODE[]			= "face-beauty-default-mode";

//ageGender-detection
const char GNCameraParameters::KEY_AGEGENDER_DETECTION_MODE[] = "agegender-detection-mode";
const char GNCameraParameters::KEY_SUPPOTED_AGEGENDER_DETECTION_MODE[] = "agegender-detection-mode-supported";
const char GNCameraParameters::AGEGENDER_DETECTION_ON[] = "on";
const char GNCameraParameters::AGEGENDER_DETECTION_OFF[] = "off";

//Pic zoom mode
const char GNCameraParameters::KEY_PICZOOM_MODE[] 					= "piczoom-mode";
const char GNCameraParameters::PICZOOM_MODE_ON[] 					= "on";
const char GNCameraParameters::PICZOOM_MODE_OFF[] 					= "off";

//Mirror mode
const char GNCameraParameters::KEY_MIRROR_MODE[] 					= "mirror-mode";
const char GNCameraParameters::KEY_SUPPOTED_MIRROR_MODE[] 			= "mirror-mode-supported";
const char GNCameraParameters::MIRROR_MODE_ON[] 					= "on";
const char GNCameraParameters::MIRROR_MODE_OFF[] 					= "off";	

// Gesture event type
const char GNCameraParameters::KEY_GESTURE_EVENT_SUPPORTED[] 		= "gesture-event-supported";
const char GNCameraParameters::KEY_GESTURE_EVENT_TYPE[] 			= "gesture-event-type";
const char GNCameraParameters::GESTURE_EVENT_NONE[] 				= "none";
const char GNCameraParameters::GESTURE_EVENT_OPEN_HAND_PRESENCE[] 	= "open-hand-presence";
const char GNCameraParameters::GESTURE_EVENT_FIST_PRESENCE[] 		= "fist-presence";
const char GNCameraParameters::GESTURE_EVENT_FACE_PRESENCE[] 		= "face-presence";

// Scene detection mode
const char GNCameraParameters::KEY_SCENE_DETECTION_MODE[] 			= "scene-detection-mode";
const char GNCameraParameters::KEY_SUPPOTED_SCENE_DETECTION_MODE[] 	= "scene-detection-mode-supported";
const char GNCameraParameters::SCENE_DETECTION_ON[] 				= "on";
const char GNCameraParameters::SCENE_DETECTION_OFF[] 				= "off";

// Capture mode
const char GNCameraParameters::KEY_CAPTURE_MODE[] 					= "cap-mode";
const char GNCameraParameters::KEY_SUPPORTED_CAPTURE_MODES[] 		= "cap-mode-supported";
const char GNCameraParameters::CAPTURE_MODE_NORMAL[] 				= "normal";
const char GNCameraParameters::CAPTURE_MODE_BURST_SHOT[] 			= "burstshot";
const char GNCameraParameters::CAPTURE_MODE_NIGHTSHOT_SHOT[] 		= "nightshot";
const char GNCameraParameters::CAPTURE_MODE_PICZOOM_SHOT[]			= "piczoom";

const char GNCameraParameters::KEY_BURST_SHOT_NUM[] 				= "burst-num";

// Live effect
const char GNCameraParameters::KEY_LIVE_EFFECT[] 					= "live-effect";
const char GNCameraParameters::KEY_SUPPORTED_LIVE_EFFECTS[] 		= "live-effect-values";
const char GNCameraParameters::LIVE_EFFECT_NONE[] 					= "none";
const char GNCameraParameters::LIVE_EFFECT_ANTIQUE[] 				= "antique";
const char GNCameraParameters::LIVE_EFFECT_CARTOON[] 				= "cartoon";
const char GNCameraParameters::LIVE_EFFECT_EMBOSS[] 				= "emboss";
const char GNCameraParameters::LIVE_EFFECT_FLIP[] 					= "flip";
const char GNCameraParameters::LIVE_EFFECT_FOG[] 					= "fog";
const char GNCameraParameters::LIVE_EFFECT_GRAYSCALE[] 				= "grayscale";
const char GNCameraParameters::LIVE_EFFECT_LOMO_BLUE[] 				= "lomo-blue";
const char GNCameraParameters::LIVE_EFFECT_LOMO_GREEN[] 			= "lomo-green";
const char GNCameraParameters::LIVE_EFFECT_LOMO_NEUTRAL[] 			= "lomo-neutral";
const char GNCameraParameters::LIVE_EFFECT_LOMO_RED[] 				= "lomo-red";
const char GNCameraParameters::LIVE_EFFECT_LOMO_YELLOW[] 			= "lomo-yellow";
const char GNCameraParameters::LIVE_EFFECT_MAGICPEN[] 				= "magicpen";
const char GNCameraParameters::LIVE_EFFECT_MILKY[] 					= "milky";
const char GNCameraParameters::LIVE_EFFECT_MIRROR[] 				= "mirror";
const char GNCameraParameters::LIVE_EFFECT_NEGATIVE[] 				= "negative";
const char GNCameraParameters::LIVE_EFFECT_OILY[] 					= "oily";
const char GNCameraParameters::LIVE_EFFECT_PAINT[] 					= "paint";
const char GNCameraParameters::LIVE_EFFECT_SEPIA[] 					= "sepia";
const char GNCameraParameters::LIVE_EFFECT_SKETCH_COLOR[]			= "sketch-color";
const char GNCameraParameters::LIVE_EFFECT_SKETCH_GRAY[] 			= "sketch-gray";
const char GNCameraParameters::LIVE_EFFECT_SOLARIZE[] 				= "solarize";
const char GNCameraParameters::LIVE_EFFECT_STAMP[] 					= "stamp";
const char GNCameraParameters::LIVE_EFFECT_DOF[] 					= "dof";
const char GNCameraParameters::LIVE_EFFECT_VIGNETTING[] 			= "vignetting";
const char GNCameraParameters::LIVE_EFFECT_WARP_FISHEYE[] 			= "warp-fisheye";
const char GNCameraParameters::LIVE_EFFECT_WARP_ALIENSCUM[] 		= "warp-alienscum";
const char GNCameraParameters::LIVE_EFFECT_WARP_BIGBUPPA[] 			= "warp-bigbuppa";
const char GNCameraParameters::LIVE_EFFECT_WARP_BOOZIEBOWL[] 		= "warp-booziebowl";
const char GNCameraParameters::LIVE_EFFECT_WARP_CONEHEAD[] 			= "warp-conehead";
const char GNCameraParameters::LIVE_EFFECT_WARP_FUNKYFRESH[] 		= "warp-funkyfresh";
const char GNCameraParameters::LIVE_EFFECT_WARP_JELLYBELLY[] 		= "warp-jellybelly";
const char GNCameraParameters::LIVE_EFFECT_WARP_PETTYPETIT[] 		= "warp-pettypetit";
const char GNCameraParameters::LIVE_EFFECT_WARP_EYEBALLEDEVY[] 		= "warp-eyeballedevy";
const char GNCameraParameters::LIVE_EFFECT_WARP_SPEEDYWEED[] 		= "warp-speedyweed";
const char GNCameraParameters::LIVE_EFFECT_MOSAIC[] 				= "mosaic";
const char GNCameraParameters::LIVE_EFFECT_FROST[] 					= "frost";
const char GNCameraParameters::LIVE_EFFECT_MOON_LIGHT[] 			= "moon-light";
const char GNCameraParameters::LIVE_EFFECT_NOISE[] 					= "noise";
const char GNCameraParameters::LIVE_EFFECT_WATER_COLOR[] 			= "water-color";
const char GNCameraParameters::LIVE_EFFECT_FLEETINGTIME[] 			= "fleetingtime";
const char GNCameraParameters::LIVE_EFFECT_CRAYON[] 				= "crayon";
const char GNCameraParameters::LIVE_EFFECT_SNOWFLAKES[] 			= "snowflakes";
const char GNCameraParameters::LIVE_EFFECT_LIGHTBEAM[] 				= "lightbeam";
const char GNCameraParameters::LIVE_EFFECT_REFLECTION[] 			= "reflection";
const char GNCameraParameters::LIVE_EFFECT_SUNSET[] 				= "sunset";
const char GNCameraParameters::LIVE_EFFECT_REVERSAL[] 				= "reversal";
const char GNCameraParameters::LIVE_EFFECT_WARMLOMO[] 				= "warmlomo";
const char GNCameraParameters::LIVE_EFFECT_COLDLOMO[] 				= "coldlomo";
const char GNCameraParameters::LIVE_EFFECT_SOFTPINK[] 				= "softpink";
const char GNCameraParameters::LIVE_EFFECT_JAPANBACKLIGHT[] 		= "japan-backlight";
const char GNCameraParameters::LIVE_EFFECT_COSMETOLOGY_BACKLIGHT[] 	= "cosmetology-backlight";
const char GNCameraParameters::LIVE_EFFECT_FINEFOOD[]				= "finefood";
const char GNCameraParameters::LIVE_EFFECT_BLACKWHITET[]			= "blackwhite";

// Map from strings to values
const GNCameraParameters::QCameraMap GNCameraParameters::CAPTURE_MODES_MAP[] = {
    {CAPTURE_MODE_NORMAL,   		CAM_CAPTURE_MODE_NORMAL },
    {CAPTURE_MODE_BURST_SHOT,  		CAM_CAPTURE_MODE_BURST },
    
#ifdef CONFIG_GN_CAMERA_FEATURE_NIGHT_SHOT_SUPPORT
    {CAPTURE_MODE_NIGHTSHOT_SHOT,  	CAM_CAPTURE_MODE_NIGHTSHOT },
#endif

#ifdef CONFIG_GN_CAMERA_FEATURE_PICZOOM_SUPPORT
	{CAPTURE_MODE_PICZOOM_SHOT,  	CAM_CAPTURE_MODE_PICZOOM },
#endif
};

const GNCameraParameters::QCameraMap GNCameraParameters::GESTURE_MODES_MAP[] = {
#ifdef CONFIG_GN_CAMERA_FEATURE_GESTURE_SHOT_SUPPORT
    {GESTURE_MODE_ON,  1},
#endif
    {GESTURE_MODE_OFF, 0},
};

const GNCameraParameters::QCameraMap GNCameraParameters::FACE_BEAUTY_MODES_MAP[] = {
#ifdef CONFIG_GN_CAMERA_FEATURE_FACE_BEAUTY_SUPPORT
    {FACE_BEAUTY_ON,  1},
#endif
    {FACE_BEAUTY_OFF, 0},
};

const GNCameraParameters::QCameraMap GNCameraParameters::AGEGENDER_DETECTION_MODES_MAP[] = {
#ifdef CONFIG_GN_CAMERA_FEATURE_AGEGENDER_DETECTION_SUPPORT
    {AGEGENDER_DETECTION_ON,  1},
#endif
    {AGEGENDER_DETECTION_OFF, 0},
};

const GNCameraParameters::QCameraMap GNCameraParameters::KEY_PICZOOM_MODES_MAP[] = {
#ifdef CONFIG_GN_CAMERA_FEATURE_PICZOOM_SUPPORT
	{PICZOOM_MODE_ON,  1},
#endif
	{PICZOOM_MODE_OFF, 0},
};

const GNCameraParameters::QCameraMap GNCameraParameters::MIRROR_MODES_MAP[] = {
#ifdef CONFIG_GN_CAMERA_FEATURE_LIVE_EFFECT_SUPPORT
    {MIRROR_MODE_ON,  1},
#endif
    {MIRROR_MODE_OFF, 0},
};

const GNCameraParameters::QCameraMap GNCameraParameters::GESTURE_EVENT_TYPES_MAP[] = {
    {GESTURE_EVENT_NONE,  				CAM_GESTURE_EVENT_NONE},
#ifdef CONFIG_GN_CAMERA_FEATURE_SCENE_DETECTION_SUPPORT
    {GESTURE_EVENT_OPEN_HAND_PRESENCE, 	CAM_GESTURE_EVENT_OPEN_HAND_PRESENCE},
	{GESTURE_EVENT_FIST_PRESENCE,		CAM_GESTURE_EVENT_FIST_PRESENCE},
    {GESTURE_EVENT_FACE_PRESENCE,  		CAM_GESTURE_EVENT_FACE_PRESENCE},
#endif
};

const GNCameraParameters::QCameraMap GNCameraParameters::SCENE_DETECTION_MODES_MAP[] = {
#ifdef CONFIG_GN_CAMERA_FEATURE_SCENE_DETECTION_SUPPORT
    {SCENE_DETECTION_ON,  1},
#endif
    {SCENE_DETECTION_OFF, 0},
};

const GNCameraParameters::QCameraMap GNCameraParameters::LIVE_EFFECTS_MAP[] = {
	{LIVE_EFFECT_NONE, 						CAM_LIVE_EFFECT_NONE},
#ifdef CONFIG_GN_CAMERA_FEATURE_LIVE_EFFECT_SUPPORT
    {LIVE_EFFECT_ANTIQUE,  					CAM_LIVE_EFFECT_ANTIQUE},
	{LIVE_EFFECT_CARTOON, 					CAM_LIVE_EFFECT_CARTOON},
	{LIVE_EFFECT_EMBOSS, 					CAM_LIVE_EFFECT_EMBOSS},
	{LIVE_EFFECT_FLIP, 						CAM_LIVE_EFFECT_FLIP},
	{LIVE_EFFECT_FOG, 						CAM_LIVE_EFFECT_FOG},
	{LIVE_EFFECT_GRAYSCALE, 				CAM_LIVE_EFFECT_GRAYSCALE},
	{LIVE_EFFECT_LOMO_BLUE, 				CAM_LIVE_EFFECT_LOMO_BLUE},
	{LIVE_EFFECT_LOMO_GREEN, 				CAM_LIVE_EFFECT_LOMO_GREEN},
	{LIVE_EFFECT_LOMO_NEUTRAL, 				CAM_LIVE_EFFECT_LOMO_NEUTRAL},
	{LIVE_EFFECT_LOMO_RED, 					CAM_LIVE_EFFECT_LOMO_RED},
	{LIVE_EFFECT_LOMO_YELLOW, 				CAM_LIVE_EFFECT_LOMO_YELLOW},
	{LIVE_EFFECT_MAGICPEN, 					CAM_LIVE_EFFECT_MAGICPEN},
	{LIVE_EFFECT_MILKY, 					CAM_LIVE_EFFECT_MILKY},
	{LIVE_EFFECT_MIRROR, 					CAM_LIVE_EFFECT_MIRROR},
	{LIVE_EFFECT_NEGATIVE, 					CAM_LIVE_EFFECT_NEGATIVE},
	{LIVE_EFFECT_OILY, 						CAM_LIVE_EFFECT_OILY},
	{LIVE_EFFECT_PAINT, 					CAM_LIVE_EFFECT_PAINT},
	{LIVE_EFFECT_SEPIA, 					CAM_LIVE_EFFECT_SEPIA},
	{LIVE_EFFECT_SKETCH_COLOR, 				CAM_LIVE_EFFECT_SKETCH_COLOR},
	{LIVE_EFFECT_SKETCH_GRAY, 				CAM_LIVE_EFFECT_SKETCH_GRAY},
	{LIVE_EFFECT_SOLARIZE, 					CAM_LIVE_EFFECT_SOLARIZE},
	{LIVE_EFFECT_STAMP, 					CAM_LIVE_EFFECT_STAMP},
	{LIVE_EFFECT_DOF, 						CAM_LIVE_EFFECT_DOF},
	{LIVE_EFFECT_VIGNETTING, 				CAM_LIVE_EFFECT_VIGNETTING},
	{LIVE_EFFECT_WARP_FISHEYE, 				CAM_LIVE_EFFECT_WARP_FISHEYE},
	{LIVE_EFFECT_WARP_ALIENSCUM,			CAM_LIVE_EFFECT_WARP_ALIENSCUM},
	{LIVE_EFFECT_WARP_BIGBUPPA, 			CAM_LIVE_EFFECT_WARP_BIGBUPPA},
	{LIVE_EFFECT_WARP_BOOZIEBOWL, 			CAM_LIVE_EFFECT_WARP_BOOZIEBOWL},
	{LIVE_EFFECT_WARP_CONEHEAD, 			CAM_LIVE_EFFECT_WARP_CONEHEAD},
	{LIVE_EFFECT_WARP_FUNKYFRESH, 			CAM_LIVE_EFFECT_WARP_FUNKYFRESH},
	{LIVE_EFFECT_WARP_JELLYBELLY, 			CAM_LIVE_EFFECT_WARP_JELLYBELLY},
	{LIVE_EFFECT_WARP_PETTYPETIT, 			CAM_LIVE_EFFECT_WARP_PETTYPETIT},
	{LIVE_EFFECT_WARP_EYEBALLEDEVY, 		CAM_LIVE_EFFECT_WARP_EYEBALLEDEVY},
	{LIVE_EFFECT_WARP_SPEEDYWEED, 			CAM_LIVE_EFFECT_WARP_SPEEDYWEED},
	{LIVE_EFFECT_MOSAIC, 					CAM_LIVE_EFFECT_MOSAIC},
	{LIVE_EFFECT_FROST, 					CAM_LIVE_EFFECT_FROST},
	{LIVE_EFFECT_MOON_LIGHT, 				CAM_LIVE_EFFECT_MOON_LIGHT},
	{LIVE_EFFECT_NOISE, 					CAM_LIVE_EFFECT_NOISE},
	{LIVE_EFFECT_WATER_COLOR, 				CAM_LIVE_EFFECT_WATER_COLOR},
	{LIVE_EFFECT_FLEETINGTIME, 				CAM_LIVE_EFFECT_FLEETINGTIME},
	{LIVE_EFFECT_CRAYON, 					CAM_LIVE_EFFECT_CRAYON},
	{LIVE_EFFECT_SNOWFLAKES, 				CAM_LIVE_EFFECT_SNOWFLAKES},
	{LIVE_EFFECT_LIGHTBEAM, 				CAM_LIVE_EFFECT_LIGHTBEAM},
	{LIVE_EFFECT_REFLECTION, 				CAM_LIVE_EFFECT_REFLECTION},
	{LIVE_EFFECT_SUNSET, 					CAM_LIVE_EFFECT_SUNSET},
	{LIVE_EFFECT_REVERSAL, 					CAM_LIVE_EFFECT_REVERSAL},
	{LIVE_EFFECT_WARMLOMO, 					CAM_LIVE_EFFECT_WARMLOMO},
	{LIVE_EFFECT_COLDLOMO, 					CAM_LIVE_EFFECT_COLDLOMO},
	{LIVE_EFFECT_SOFTPINK, 					CAM_LIVE_EFFECT_SOFTPINK},
	{LIVE_EFFECT_JAPANBACKLIGHT, 			CAM_LIVE_EFFECT_JAPANBACKLIGHT},
	{LIVE_EFFECT_COSMETOLOGY_BACKLIGHT, 	CAM_LIVE_EFFECT_COSMETOLOGY_BACKLIGHT},
	{LIVE_EFFECT_FINEFOOD, 					CAM_LIVE_EFFECT_FINEFOOD},
	{LIVE_EFFECT_BLACKWHITET, 				CAM_LIVE_EFFECT_BLACKWHITE},
#endif
};

GNCameraParameters::GNCameraParameters()
	: QCameraParameters()
	, m_bFaceBeautyMode(false)
	, m_nBurstNum(0)
	, m_nCaptureMode(CAM_CAPTURE_MODE_NORMAL)
	, m_nLiveEffect(CAM_LIVE_EFFECT_NONE)
{

}

GNCameraParameters::GNCameraParameters(const String8 &params)
	: QCameraParameters(params)
	, m_bFaceBeautyMode(false)
	, m_nBurstNum(0)
	, m_nCaptureMode(CAM_CAPTURE_MODE_NORMAL)
	, m_nLiveEffect(CAM_LIVE_EFFECT_NONE)
{

}

GNCameraParameters::~GNCameraParameters()
{
	
}

int32_t 
GNCameraParameters::init(cam_capability_t *capabilities, mm_camera_vtbl_t *mmOps, QCameraAdjustFPS *adjustFPS, QCameraTorchInterface *torch)
{
	int32_t rc = NO_ERROR;

	setDefaultParameters();

	rc = QCameraParameters::init(capabilities, mmOps, adjustFPS, torch);

	return rc;
}

int32_t 
GNCameraParameters::updateParameters(GNCameraParameters& params, bool &needRestart)
{
	int32_t rc = NO_ERROR;
	int32_t final_rc = NO_ERROR;

	if ((rc = setCaptureMode(params)))					final_rc = rc; 
	if ((rc = setFaceBeautyMode(params)))				final_rc = rc; 
	if ((rc = setMirrorMode(params)))					final_rc = rc; 
	if ((rc = setGestureShotMode(params)))				final_rc = rc; 
	if ((rc = setGestureDetectionType(params)))		final_rc = rc; 
	if ((rc = setSceneDetection(params)))				final_rc = rc; 
	if ((rc = setPictureFrame(params)))				final_rc = rc; 
	if ((rc = setLiveEffect(params)))					final_rc = rc; 
	if ((rc = setAgeGenderDetectionMode(params)))		final_rc = rc;
	if ((rc = setPicZoomMode(params)))					final_rc = rc;
	if ((rc = QCameraParameters::updateParameters(params, needRestart)))		final_rc = rc; 

	return final_rc;
}

int32_t 
GNCameraParameters::setDefaultParameters()
{
	int32_t rc = NO_ERROR;

	// Set capture mode
	String8 captureModes = createValuesStringFromMap(
           CAPTURE_MODES_MAP, sizeof(CAPTURE_MODES_MAP) / sizeof(QCameraMap));
	set(KEY_SUPPORTED_CAPTURE_MODES, captureModes);
    set(KEY_CAPTURE_MODE, CAPTURE_MODE_NORMAL);

	// Set live effect
	String8 liveEffects = createValuesStringFromMap(
           LIVE_EFFECTS_MAP, sizeof(LIVE_EFFECTS_MAP) / sizeof(QCameraMap));
	set(KEY_SUPPORTED_LIVE_EFFECTS, liveEffects);
    set(KEY_LIVE_EFFECT, LIVE_EFFECT_NONE);

	//Set Gesture mode
#ifdef CONFIG_GN_CAMERA_FEATURE_GESTURE_SHOT_SUPPORT
	set(KEY_GESTURE_SUPPORTED, VALUE_TRUE);
#else
	set(KEY_GESTURE_SUPPORTED, VALUE_FALSE);
#endif
    set(KEY_GESTURE_MODE, GESTURE_MODE_OFF);

	// Set face beauty mode
#ifdef CONFIG_GN_CAMERA_FEATURE_FACE_BEAUTY_SUPPORT
	set(KEY_SUPPOTED_FACE_BEAUTY_MODE, VALUE_TRUE);
#else
	set(KEY_SUPPOTED_FACE_BEAUTY_MODE, VALUE_FALSE);
#endif
    set(KEY_FACE_BEAUTY_MODE, FACE_BEAUTY_OFF);

	// Set age gender detection mode
#ifdef CONFIG_GN_CAMERA_FEATURE_AGEGENDER_DETECTION_SUPPORT
	set(KEY_SUPPOTED_AGEGENDER_DETECTION_MODE, VALUE_TRUE);
#else
	set(KEY_SUPPOTED_AGEGENDER_DETECTION_MODE, VALUE_FALSE);
#endif
    set(KEY_AGEGENDER_DETECTION_MODE, AGEGENDER_DETECTION_OFF);

	// Set mirror mode
#ifdef CONFIG_GN_CAMERA_FEATURE_LIVE_EFFECT_SUPPORT
	set(KEY_SUPPOTED_MIRROR_MODE, VALUE_TRUE);
#else
	set(KEY_SUPPOTED_MIRROR_MODE, VALUE_FALSE);
#endif
    set(KEY_MIRROR_MODE, MIRROR_MODE_OFF);

	// Set gesture event type
#ifdef CONFIG_GN_CAMERA_FEATURE_GESTURE_DETECTION_SUPPORT
	set(KEY_GESTURE_EVENT_SUPPORTED, VALUE_TRUE);
#else
	set(KEY_GESTURE_EVENT_SUPPORTED, VALUE_FALSE);
#endif
    set(KEY_GESTURE_EVENT_TYPE, GESTURE_EVENT_NONE);

	// Set scene detection
#ifdef CONFIG_GN_CAMERA_FEATURE_SCENE_DETECTION_SUPPORT
	set(KEY_SUPPOTED_SCENE_DETECTION_MODE, VALUE_TRUE);
#else
	set(KEY_SUPPOTED_SCENE_DETECTION_MODE, VALUE_FALSE);
#endif
    set(KEY_SCENE_DETECTION_MODE, SCENE_DETECTION_OFF);

	// Set picture frame
#ifdef CONFIG_GN_CAMERA_FEATURE_PICTURE_FRAME_SUPPORT
	set(KEY_PICTURE_FRAME_SUPPORTED, VALUE_TRUE);
#else
	set(KEY_PICTURE_FRAME_SUPPORTED, VALUE_FALSE);
#endif
	set(KEY_PICTURE_FRAME, PICTURE_FRAME_NORMAL);

	return rc;
}

int32_t 
GNCameraParameters::getNumOfExtraNightShotInBufsIfNeeded() 
{
	int32_t numOfBufs = 0;
	
	if (m_nCaptureMode == CAM_CAPTURE_MODE_NIGHTSHOT) {
		numOfBufs = 4;
	}

	return numOfBufs;
}

int32_t 
GNCameraParameters::getNumOfExtraNightShotOutBufsIfNeeded() 
{
	int32_t numOfBufs = 0;
	
	if (m_nCaptureMode == CAM_CAPTURE_MODE_NIGHTSHOT) {
		numOfBufs = 1;
	}

	return numOfBufs;
}

int32_t 
GNCameraParameters::getNumOfExtraNightShotBurst() 
{
	int32_t numOfShot = 0;
	
	if (m_nCaptureMode == CAM_CAPTURE_MODE_NIGHTSHOT) {
		numOfShot = 400;
	}

	return numOfShot;
}

int32_t 
GNCameraParameters::setCaptureMode(GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_CAPTURE_MODE);
	const char *prev_str = get(KEY_CAPTURE_MODE);

    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {	
        	rc = setCaptureMode(str);
		}
    }

	if (m_nCaptureMode == CAM_CAPTURE_MODE_BURST) {
		m_nBurstNum = params.getInt(KEY_BURST_SHOT_NUM);
	} else if (m_nCaptureMode == CAM_CAPTURE_MODE_NIGHTSHOT) {
		m_nBurstNum = 1;
	} else {
		m_nBurstNum = 0;
	}

	return rc;
}

int32_t 
GNCameraParameters::setCaptureMode(const char *capMode)
{
	int32_t rc = NO_ERROR;

	if (capMode != NULL) {
        int32_t value = lookupAttr(CAPTURE_MODES_MAP,
                                   sizeof(CAPTURE_MODES_MAP)/sizeof(QCameraMap),
                                   capMode);
        if (value != NAME_NOT_FOUND) {
            set(KEY_CAPTURE_MODE, capMode);
			m_nCaptureMode = value;
        }
    }

	return rc;
}

int32_t 
GNCameraParameters::setFaceBeautyMode(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_FACE_BEAUTY_MODE);
	const char *prev_str = get(KEY_FACE_BEAUTY_MODE);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(FACE_BEAUTY_MODES_MAP,
                                   sizeof(FACE_BEAUTY_MODES_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_FACE_BEAUTY_MODE, str);
				m_bFaceBeautyMode = (value == 1);
	        }
		}

		if (m_bFaceBeautyMode) {
			set(KEY_FACE_BEAUTY_SUB_MODE, params.getStr(KEY_FACE_BEAUTY_SUB_MODE));
			set(KEY_FACE_BEAUTY_AGEGENDER_LEVEL, params.getStr(KEY_FACE_BEAUTY_AGEGENDER_LEVEL));

			set(KEY_FACE_BEAUTY_LEVEL, params.getInt(KEY_FACE_BEAUTY_LEVEL));
			set(KEY_SLENDER_FACE_LEVEL, params.getInt(KEY_SLENDER_FACE_LEVEL));
			set(KEY_SKIN_SOFTEN_LEVEL, params.getInt(KEY_SKIN_SOFTEN_LEVEL));
			set(KEY_EYE_ENLARGMENT_LEVEL, params.getInt(KEY_EYE_ENLARGMENT_LEVEL));
		}
    }

	return rc;
}

int32_t
GNCameraParameters::setAgeGenderDetectionMode(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_AGEGENDER_DETECTION_MODE);
	const char *prev_str = get(KEY_AGEGENDER_DETECTION_MODE);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(AGEGENDER_DETECTION_MODES_MAP,
                                   sizeof(AGEGENDER_DETECTION_MODES_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_AGEGENDER_DETECTION_MODE, str);
				m_bAgeGenderDetectionMode = (value == 1);
	        }
		}

		if (m_bFaceBeautyMode) {
			set(KEY_AGEGENDER_DETECTION_MODE, params.getStr(KEY_AGEGENDER_DETECTION_MODE));
		}
    }

	return rc;
}

int32_t 
GNCameraParameters::setMirrorMode(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_MIRROR_MODE);
	const char *prev_str = get(KEY_MIRROR_MODE);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(MIRROR_MODES_MAP,
                                   sizeof(MIRROR_MODES_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_MIRROR_MODE, str);
	        }
		}
    }

	return rc;
}

int32_t 
GNCameraParameters::setGestureShotMode(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_GESTURE_MODE);
	const char *prev_str = get(KEY_GESTURE_MODE);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(GESTURE_MODES_MAP,
                                   sizeof(GESTURE_MODES_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_GESTURE_MODE, str);
	        }
		}
    }

	return rc;
}

int32_t 
GNCameraParameters::setGestureDetectionType(const GNCameraParameters& params) 
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_GESTURE_EVENT_TYPE);
	const char *prev_str = get(KEY_GESTURE_EVENT_TYPE);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(GESTURE_EVENT_TYPES_MAP,
                                   sizeof(GESTURE_EVENT_TYPES_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_GESTURE_EVENT_TYPE, str);
	        }
		}
    }

	return rc;
}

int32_t 
GNCameraParameters::setSceneDetection(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_SCENE_DETECTION_MODE);
	const char *prev_str = get(KEY_SCENE_DETECTION_MODE);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(SCENE_DETECTION_MODES_MAP,
                                   sizeof(SCENE_DETECTION_MODES_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_SCENE_DETECTION_MODE, str);
	        }
		}
    }

	return rc;
}

int32_t 
GNCameraParameters::setPictureFrame(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_PICTURE_FRAME);
	const char *prev_str = get(KEY_PICTURE_FRAME);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
	    	set(KEY_PICTURE_FRAME, str);
		}
    }

	return rc;
}

int32_t 
GNCameraParameters::setLiveEffect(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_LIVE_EFFECT);
	const char *prev_str = get(KEY_LIVE_EFFECT);
	
    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(LIVE_EFFECTS_MAP,
                                   sizeof(LIVE_EFFECTS_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_LIVE_EFFECT, str);
				m_nLiveEffect = value;
	        }
		}
    }

	return rc;
}

int32_t
GNCameraParameters::setPicZoomMode(const GNCameraParameters& params)
{
	int32_t rc = NO_ERROR;

	const char *str = params.get(KEY_PICZOOM_MODE);
	const char *prev_str = get(KEY_PICZOOM_MODE);

    if (str != NULL) {
		if (prev_str == NULL || strcmp(str, prev_str) != 0) {
			int32_t value = lookupAttr(KEY_PICZOOM_MODES_MAP,
                                   sizeof(KEY_PICZOOM_MODES_MAP)/sizeof(QCameraMap),
                                   str);
	        if (value != NAME_NOT_FOUND) {
	            set(KEY_PICZOOM_MODE, str);
	        }
		}
    }

	return rc;
}

int 	
GNCameraParameters::lookupAttr(const QCameraMap arr[], int len, const char *name)
{
	 if (name != NULL) {
        for (int i = 0; i < len; i++) {
            if (!strcmp(arr[i].desc, name))
                return arr[i].val;
        }
    }
	 
    return NAME_NOT_FOUND;
}

String8 
GNCameraParameters::createValuesStringFromMap(const QCameraMap* map, int map_len)
{
    String8 str;

    for (int i = 0; i < map_len; i++) {
        if (NULL != map[i].desc) {
            if (i > 0) {
                str.append(",");
            }
            str.append(map[i].desc);
        }
    }
    return str;
}

}; //namespace qcamera

#endif //ORIGINAL_VERSION