/* ===============================================================================
 * Copyright (c) 2016 Pikkart S.r.l. All Rights Reserved.
 * Pikkart is a trademark of Pikkart S.r.l., registered in Europe,
 * the United States and other countries.
 *
 * This file is part of Pikkart AR Recognition SDK.
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
 * ===============================================================================*/

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import <AVFoundation/AVFoundation.h>

#import "PKTRecognitionOptions.h"
#import "PKTIRecognitionListener.h"
#import "PKTINetworkInfoProvider.h"


typedef void(^PKTRecognitionControllerCompletionHandler)(); /**< Completion Handler used in Recognition Reset */

typedef NS_ENUM(NSInteger, PKTRecognitionFocusMode) {
    PKTFocusModeLocked              = AVCaptureFocusModeLocked,
    PKTFocusModeAutoFocus           = AVCaptureFocusModeAutoFocus,
    PKTFocusModeContinuousAutoFocus = AVCaptureFocusModeContinuousAutoFocus,
    PKTFocusModeCenter = PKTFocusModeContinuousAutoFocus + 1,
    PKTFocusModeCenterTap = PKTFocusModeContinuousAutoFocus +2
};
/**
 * \class PKTRecognitionController
 * \brief The Pikkart Augmented Reality View Controller
 *
 * The  Pikkart Augmented Reality View Controller.
 * It allows photo camera access and recognition phase
 *
 *
 * \code
 * StartRecognition:andRecognitionCallback:
 * \endcode
 */
@interface PKTRecognitionController : GLKViewController<PKTIRecognitionListener,PKTINetworkInfoProvider>

/*! \brief Start Recognition Session
 *
 *  \param recognitionOptions PKTRecognitionOptions parameter
 *  \param recognitionCallback instance conforms to PKTIRecognitionListener protocol
 */
-(void)StartRecognition:(PKTRecognitionOptions *)recognitionOptions
 andRecognitionCallback:(id<PKTIRecognitionListener>) recognitionCallback;

/*! \brief Stop Recognition Session without AVCaptureSession reset
 *
 */
-(void)StopRecognition;

/*! \brief Stop Recognition Session with AVCaptureSession reset
 *
 *  \param completionHandler completion handler called after session is stopped and resetted
 */
-(void)CloseWithSessionReset:(PKTRecognitionControllerCompletionHandler)completionHandler;
/*! \brief Change recognition options on current session
 *
 *  \param options PKTRecognitionOptions parameter
 */
-(void)ChangeRecognitionOptions:(PKTRecognitionOptions*) options;

/*! \brief Check if  recognition session is running
 *  \return bool recognition running
 */
-(bool)isActive;

/*! \brief Check if  recognition session has been tracked a marker
 *
 *  \return bool recognition is tracking
 */
-(bool)isTracking;

/*! \brief Get Current Tracking Marker
 *
 *  \return PKTMarker current tracking marker
 */
-(PKTMarker *) getCurrentMarker;

/*! \brief Get Current Projection Matrix
 *
 *  \param float ** Current projection matrix
 */
-(void)getCurrentProjectionMatrix:(float **)matrixPointer;

/*! \brief Get Current Model View Matrix
 *
 *  \param float ** Current model view matrix
 */
-(void)getCurrentModelViewMatrix:(float **)matrixPointer;

/*! \brief Enable Torch on device, if available
 *
 *  \return bool torch state
 */
-(bool)enableTorch;

/*! \brief Disable Torch on device, if available
 *
 *  \return bool torch state
 */
-(bool)disableTorch;

/*! \brief Render Camera configuration
 *
 *  \param viewPortSize View Port Size
 *  \param angle angolo della fotocamera
 */
-(void)RenderCameraWithViewPortSize:(CGSize) viewPortSize
                           andAngle:(int)angle;

/*! \brief Set focus mode on Capture Device
 *
 *  \param focusMode focus mode
 */
-(void)setFocusMode:(PKTRecognitionFocusMode)focusMode;

/*! \brief Get focus mode on Capture Device
 *
 *  \return AVCaptureFocusMode focus mode
 */
-(PKTRecognitionFocusMode)getFocusMode;

/*! \brief Set marker Cache Size
 *
 *  \param markerCacheSize marker Cache Size
 */
-(void)setMarkerCacheSize:(int) markerCacheSize;

/**
 * \brief Disable the recognition system.
 */
-(void) DisableRecognition;

/**
 * \brief Enables the recognition system.
 */
-(void)EnableRecognition;

/**
 * \brief Is the recognition system enabled.
 */
-(bool)IsRecognitionEnabled;

/**
 * \brief enable the orange dots recognition effect
 */
-(void)EnableRecognitionEffect;

/**
 * \brief disable the orange dots recognition effect
 */
-(void)DisableRecognitionEffect;

@end
