package com.ankamagames.wakfu.client.binaryStorage;

public class NationColorsBinaryData implements dEZ {
    protected int az;
    protected String drV;
    
    public NationColorsBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public String getColor()
    {
        return this.drV;
    }
    
    public void reset()
    {
        this.az = 0;
        this.drV = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.drV = a.clg().intern();
    }
    
    final public int gZ()
    {
        return aPw.eEo.getId();
    }
}