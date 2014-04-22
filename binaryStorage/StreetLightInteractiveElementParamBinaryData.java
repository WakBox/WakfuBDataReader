package com.ankamagames.wakfu.client.binaryStorage;

public class StreetLightInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int dKc;
    protected float dKd;
    protected int bPa;
    protected boolean ere;
    protected int dKf;
    protected boolean dKg;
    protected int dKh;
    protected int dKi;
    protected boolean dKj;
    protected int dKk;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public StreetLightInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int aFz()
    {
        return this.dKc;
    }
    
    public float aFA()
    {
        return this.dKd;
    }
    
    public int NX()
    {
        return this.bPa;
    }
    
    public boolean aVA()
    {
        return this.ere;
    }
    
    public int aFC()
    {
        return this.dKf;
    }
    
    public boolean aFD()
    {
        return this.dKg;
    }
    
    public int aFE()
    {
        return this.dKh;
    }
    
    public int aFF()
    {
        return this.dKi;
    }
    
    public boolean aFG()
    {
        return this.dKj;
    }
    
    public int aFH()
    {
        return this.dKk;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.dKc = 0;
        this.dKd = 0.0f;
        this.bPa = 0;
        this.ere = false;
        this.dKf = 0;
        this.dKg = false;
        this.dKh = 0;
        this.dKi = 0;
        this.dKj = false;
        this.dKk = 0;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.dKc = a.getInt();
        this.dKd = a.getFloat();
        this.bPa = a.getInt();
        this.ere = a.readBoolean();
        this.dKf = a.getInt();
        this.dKg = a.readBoolean();
        this.dKh = a.getInt();
        this.dKi = a.getInt();
        this.dKj = a.readBoolean();
        this.dKk = a.getInt();
        int i = a.get();
        if(i == 0)
        {
            this.UB = null;
        }
        else
        {
            this.UB = new com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData();
            this.UB.a(a);
        }
    }
    
    final public int gZ()
    {
        return aPw.eEI.getId();
    }
}