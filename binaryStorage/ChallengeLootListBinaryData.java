package com.ankamagames.wakfu.client.binaryStorage;

public class ChallengeLootListBinaryData implements dEZ {
    protected int az;
    protected bYf[] hsi;
    
    public ChallengeLootListBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public bYf[] cei()
    {
        return this.hsi;
    }
    
    public void reset()
    {
        this.az = 0;
        this.hsi = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getInt();
        this.hsi = new bYf[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.hsi[i0] = new bYf();
            this.hsi[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eER.getId();
    }
}