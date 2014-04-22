package com.ankamagames.wakfu.client.binaryStorage;

public class LootChestInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int UA;
    protected int mZK;
    protected int aQR;
    protected int mAT;
    protected int mAU;
    protected boolean dDy;
    protected int mAV;
    protected int mZL;
    protected String aZr;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public LootChestInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public int dIB()
    {
        return this.mZK;
    }
    
    public int rS()
    {
        return this.aQR;
    }
    
    public int dwL()
    {
        return this.mAT;
    }
    
    public int dwM()
    {
        return this.mAU;
    }
    
    public boolean aDn()
    {
        return this.dDy;
    }
    
    public int dwO()
    {
        return this.mAV;
    }
    
    public int dIC()
    {
        return this.mZL;
    }
    
    public String vS()
    {
        return this.aZr;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.UA = 0;
        this.mZK = 0;
        this.aQR = 0;
        this.mAT = 0;
        this.mAU = 0;
        this.dDy = false;
        this.mAV = 0;
        this.mZL = 0;
        this.aZr = null;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.UA = a.getInt();
        this.mZK = a.getInt();
        this.aQR = a.getInt();
        this.mAT = a.getInt();
        this.mAU = a.getInt();
        this.dDy = a.readBoolean();
        this.mAV = a.getInt();
        this.mZL = a.getInt();
        this.aZr = a.clg().intern();
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
        return aPw.eEb.getId();
    }
}