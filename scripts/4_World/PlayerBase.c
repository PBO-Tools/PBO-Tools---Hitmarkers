modded class PlayerBase {
    override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef) {
        if (GetRustHitMarkersConfig().ShouldTrigger(this)) {
            PlayerBase killer;
            if (Class.CastTo(killer, source) || Class.CastTo(killer, source.GetHierarchyParent()))
                GetRPCManager().SendRPC("HitMarkers", "PlayerHitMarkers", new Param1 < string > (dmgZone), false, killer.GetIdentity(), killer);
        }
        super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
    }
    private bool show;
    autoptr array < string > zones = {
        "Zone_Head"
    };
    void PlayerBase() {
        GetRPCManager().AddRPC("HitMarkers", "PlayerHitMarkers", this, SingleplayerExecutionType.Both);
    }
    void PlayerHitMarkers(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target) {
        Param1 < string > data;
        if (!ctx.Read(data)) return;

        if (type == CallType.Client) {
            TriggerHit(data.param1);
        }
    }
    void TriggerHit(string dmgZone) {
        if (!GetGame().IsServer()) {
            if (zones.Find(dmgZone) == -1)
                dmgZone = "Zone_All";
            EffectSound sound = SEffectManager.PlaySound(string.Format("Rustlike_Hitmarker_SoundSet_%1", dmgZone), GetPosition());
            sound.SetSoundAutodestroy(true);
            if (!ShowHitMarker())
                SetMarker(true);
            GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SetMarker, 250, false, false);
        }
    }

    void SetMarker(bool value) {
        show = value;
        SetSynchDirty();
    }

    bool ShowHitMarker() {
        return show;
    }
};