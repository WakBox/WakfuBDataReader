package com.ankamagames.wakfu.client.binaryStorage;

public class NationRankBinaryData implements dEZ {
    protected int az;
    protected float bEe;
    protected String aZr;
    protected int bEf;
    
    public NationRankBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public float KY()
    {
        return this.bEe;
    }
    
    public String vS()
    {
        return this.aZr;
    }
    
    public int KZ()
    {
        return this.bEf;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bEe = 0.0f;
        this.aZr = null;
        this.bEf = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.bEe = a.getFloat();
        this.aZr = a.clg().intern();
        this.bEf = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eEq.getId();
    }
}