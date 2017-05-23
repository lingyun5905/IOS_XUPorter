using UnityEngine;
using System.Collections;


namespace UnityEditor.XCodeEditor{
	

	public class XCProjectSystemTeamID  {
		
		
		public static XCProjectSystemTeamID createWithProject(PBXProject project){
			
			XCProjectSystemTeamID SystemTeamID = new XCProjectSystemTeamID (); 
			SystemTeamID.weakProject = project;
			return SystemTeamID;
		}
		
		public PBXProject weakProject;
		
		public void visitAddSystemTargetTeamID (string teamid){
			
			if (weakProject == null) {
				Debug.Log ("weakProject must not be null");
				return;
			}
			
			PBXDictionary _Attributes = (PBXDictionary)weakProject.data ["attributes"];
			PBXDictionary _TargetAttributes = (PBXDictionary)_Attributes ["TargetAttributes"];
			PBXList _targets = (PBXList)weakProject.data ["targets"];
			PBXDictionary targetDict = null;
			if (_TargetAttributes.ContainsKey ((string)_targets [0])) {
				targetDict = (PBXDictionary)_TargetAttributes [(string)_targets [0]];
			} else {
				//不会发生
				//return;
				targetDict = new PBXDictionary();
			}

			if (targetDict != null && targetDict.ContainsKey ("DevelopmentTeam")) {
				targetDict.Remove("DevelopmentTeam");
			}
			targetDict.Add ("DevelopmentTeam", teamid);

			if (!_TargetAttributes.ContainsKey ((string)_targets [0])) {
				_TargetAttributes.Add((string)_targets [0],targetDict);
			}
			
		}
	}
	
}

