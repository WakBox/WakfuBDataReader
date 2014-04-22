package com.ankamagames.wakfu.client.binaryStorage;

public class ArcadeChallengeBinaryData implements dEZ {
    protected int az;
    
    public ArcadeChallengeBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public void reset()
    {
        this.az = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eFb.getId();
    }
}