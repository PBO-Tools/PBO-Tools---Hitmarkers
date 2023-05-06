class CfgPatches
{
	class SIXHitmarker
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class SIXHitmarker
	{
		dir="SIXHitmarker";
		hideName=1;
		hidePicture=1;
		name="SIXHitmarker";
		credits="";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"SIXHitmarkers/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SIXHitmarkers/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"SIXHitmarkers/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgSoundShaders
{
	class Hitmarker_SoundShader
	{
		samples[]=
		{
			
			{
				"\SIXHitmarkers\Data\Sounds\Hitmarker",
				1
			}
		};
		volume=1;
		range=100;
	};
	class Hitmarker_Crit_SoundShader
	{
		samples[]=
		{
			
			{
				"\SIXHitmarkers\Data\Sounds\HitMarkerCrit",
				1
			}
		};
		volume=1;
		range=100;
	};
};
class CfgSoundSets
{
	class Hitmarker_SoundSet_Zone_Head
	{
		soundShaders[]=
		{
			"Hitmarker_Crit_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class Hitmarker_SoundSet_Zone_All
	{
		soundShaders[]=
		{
			"Hitmarker_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
};
