package com.ankamagames.wakfu.client.binaryStorage;

public class LightLootListBinaryData implements dEZ {
    protected int az;
    protected bri[] iHn;
    
    public LightLootListBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public bri[] cCD()
    {
        return this.iHn;
    }
    
    public void reset()
    {
        this.az = 0;
        this.iHn = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getInt();
        this.iHn = new bri[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.iHn[i0] = new bri();
            this.iHn[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFz.getId();
    }
}