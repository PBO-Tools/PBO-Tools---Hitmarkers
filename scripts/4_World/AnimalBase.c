modded class AnimalBase {
    override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef) {
        if (GetRustHitMarkersConfig().ShouldTrigger(this)) {
            PlayerBase killer;
            if (Class.CastTo(killer, source) || Class.CastTo(killer, source.GetHierarchyParent()))
                GetRPCManager().SendRPC("HitMarkers", "PlayerHitMarkers", new Param1 < string > (dmgZone), false, killer.GetIdentity(), killer);
        }

        super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
    }
}