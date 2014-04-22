package com.ankamagames.wakfu.client.binaryStorage;

public class EffectGroupBinaryData implements dEZ {
    protected int az;
    protected int[] bav;
    
    public EffectGroupBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bav = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.bav = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eDS.getId();
    }
}