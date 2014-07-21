package com.ankamagames.wakfu.client.binaryStorage;

public class MonsterTypePestBinaryData implements dEZ {
    protected int az;
    protected int aKQ;
    protected int bzc;
    
    public MonsterTypePestBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int nU()
    {
        return this.aKQ;
    }
    
    public int IJ()
    {
        return this.bzc;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aKQ = 0;
        this.bzc = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aKQ = a.getInt();
        this.bzc = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eEl.getId();
    }
}