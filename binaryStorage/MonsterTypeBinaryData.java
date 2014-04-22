package com.ankamagames.wakfu.client.binaryStorage;

public class MonsterTypeBinaryData implements dEZ {
    protected int az;
    protected int biA;
    protected byte btd;
    
    public MonsterTypeBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int AF()
    {
        return this.biA;
    }
    
    public byte getType()
    {
        int i = this.btd;
        return (byte)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.biA = 0;
        this.btd = (byte)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.biA = a.getInt();
        int i = a.get();
        this.btd = (byte)i;
    }
    
    final public int gZ()
    {
        return aPw.eEk.getId();
    }
}