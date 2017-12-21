//
//  RootController.swift
//  testRecognitionFrameworkApp
//
//  Created by Roberto Avanzi on 25/07/16.
//  Copyright © 2016 Pikkart. All rights reserved.
//

import UIKit

class RootViewController: UIViewController,PKTIRecognitionListener {
    var mainCtrl:ViewController?

    @IBAction func openAR(_ sender: UIButton) {
        mainCtrl=ViewController();
        self.present(mainCtrl!,animated: true,
                     completion: {
                        let authInfo:PKTCloudRecognitionInfo = PKTCloudRecognitionInfo(databaseName: "")
                        let options:PKTRecognitionOptions = PKTRecognitionOptions(recognitionStorage:.PKTLOCAL, andMode: .PKTRECOGNITION_CONTINUOS_SCAN,andCloudAuthInfo:authInfo )
                        // tutorial for start recognition
                        self.mainCtrl!.startRecognition(options,
                                                        andRecognitionCallback:self)
        });
    }
    
//# MARK: PKTIRecognitionListener methods
    func executingCloudSearch() {
            print("executingCloudSearch called")
    }
    
    func cloudMarkerNotFound() {
        print("cloudMarkerNotFound called")

    }
    
    func markerNotFound() {
        print("markerNotFound called")

    }
    
    func markerTrackingLost(_ markerId: String) {
        print("markerTrackingLost called")
        mainCtrl!.selectMonkey(monkeyID: 0)
        /*
        OperationQueue.main.addOperation {
            let alertController = UIAlertController(title: "Lost Marker",
                                                    message: "marker lost with id"+markerId, preferredStyle: UIAlertControllerStyle.alert)
            let okAction = UIAlertAction(title: "OK", style: UIAlertActionStyle.default) { (result : UIAlertAction) -> Void in
                print("OK button touched")
            }
            alertController.addAction(okAction)
            self.present(alertController, animated: true, completion: nil)
        }
         */
    }
    
    func internetConnectionNeeded() {
        print("internetConnectionNeeded called")

    }
    
    func markerFound(_ marker: PKTMarker!) {
        print("markerFound called")
        /*
        OperationQueue.main.addOperation {
            let alertController = UIAlertController(title: "Marker Found", message: "marker Found with id"+marker.markerId!, preferredStyle: UIAlertControllerStyle.alert)
            let okAction = UIAlertAction(title: "OK", style: UIAlertActionStyle.default) { (result : UIAlertAction) -> Void in
                print("OK button touched")
            }
            alertController.addAction(okAction)
            self.present(alertController, animated: true, completion: nil)
        }
        */
    }
    
    func isConnectionAvailable() -> Bool {
        return false
    }
    // Arlogo callback
    func arLogoFound(_ markerId: String!, withCode code: NSNumber!) {
        print("arLogo called with code = \(code)")
        
        switch (code.intValue) {
            case 97703:
                mainCtrl!.selectMonkey(monkeyID: 1)
            case 84895:
                mainCtrl!.selectMonkey(monkeyID: 2)
            case 65266:
                mainCtrl!.selectMonkey(monkeyID: 3)
            default:
                mainCtrl!.selectMonkey(monkeyID: 1)
        }
    }
    
//# MARK: View lifecycle

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override var shouldAutorotate : Bool {
        return true
    }
    
    override var supportedInterfaceOrientations : UIInterfaceOrientationMask {
        return .all
    }

}

