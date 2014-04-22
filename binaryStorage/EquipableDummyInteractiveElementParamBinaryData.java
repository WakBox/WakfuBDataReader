package com.ankamagames.wakfu.client.binaryStorage;

public class EquipableDummyInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected String Xl;
    protected byte aOB;
    
    public EquipableDummyInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public String getAnimName()
    {
        return this.Xl;
    }
    
    public byte zp()
    {
        int i = this.aOB;
        return (byte)i;
    }
    
    public void reset()
    {
        this.az = 0;
        this.Xl = null;
        this.aOB = (byte)0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.Xl = a.clg().intern();
        int i = a.get();
        this.aOB = (byte)i;
    }
    
    final public int gZ()
    {
        return aPw.eFr.getId();
    }
}