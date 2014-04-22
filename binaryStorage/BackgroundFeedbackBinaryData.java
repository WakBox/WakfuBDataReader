package com.ankamagames.wakfu.client.binaryStorage;

public class BackgroundFeedbackBinaryData implements dEZ {
    protected int az;
    protected short eqi;
    protected dht[] lvL;
    
    public BackgroundFeedbackBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short getType()
    {
        int i = this.eqi;
        return (short)i;
    }
    
    public dht[] cZm()
    {
        return this.lvL;
    }
    
    public void reset()
    {
        this.az = 0;
        this.eqi = (short)0;
        this.lvL = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.eqi = (short)i;
        int i0 = a.getInt();
        this.lvL = new dht[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.lvL[i1] = new dht();
            this.lvL[i1].a(a);
            i1 = i1 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDv.getId();
    }
}