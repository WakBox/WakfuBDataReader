package com.ankamagames.wakfu.client.binaryStorage;

public class BackgroundInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int UA;
    protected int bCI;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public BackgroundInteractiveElementParamBinaryData()
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
    
    public int Kh()
    {
        return this.bCI;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.UA = 0;
        this.bCI = 0;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.UA = a.getInt();
        this.bCI = a.getInt();
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
        return aPw.eDw.getId();
    }
}