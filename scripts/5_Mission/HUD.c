modded class IngameHud {
    protected Widget hit;
    protected ImageWidget hitIcon;

    void IngameHud() {
        hit = GetGame().GetWorkspace().CreateWidgets("SIXHitmarkers_Client/data/gui/hud_hitmarker.layout");
        hit.SetPos(0.5, 0.5);

        hitIcon = ImageWidget.Cast(hit.FindAnyWidget("MarkerIcon"));
        hitIcon.LoadImageFile(0, "SIXHitmarkers_Client/data/gui/hitmarker.edds");
        hitIcon.SetColor(ARGB(255, 255, 255, 255));
        hitIcon.SetImage(0);
        hitIcon.Show(false);
    }

    override void Update(float timeslice) {
        super.Update(timeslice);

        PlayerBase player;
        if (Class.CastTo(player, GetGame().GetPlayer()))
            hitIcon.Show(player.ShowHitMarker());
    }
};