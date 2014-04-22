package com.ankamagames.wakfu.client.binaryStorage;

public class MonsterTypeRelashionshipBinaryData implements dEZ {
    protected int az;
    protected int gjo;
    protected int gjp;
    
    public MonsterTypeRelashionshipBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int bIm()
    {
        return this.gjo;
    }
    
    public int bIn()
    {
        return this.gjp;
    }
    
    public void reset()
    {
        this.az = 0;
        this.gjo = 0;
        this.gjp = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.gjo = a.getInt();
        this.gjp = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eEm.getId();
    }
}