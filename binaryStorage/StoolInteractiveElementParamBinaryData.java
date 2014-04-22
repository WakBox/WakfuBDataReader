package com.ankamagames.wakfu.client.binaryStorage;

public class StoolInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected String Uz;
    protected int UA;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public StoolInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public String gW()
    {
        return this.Uz;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.Uz = null;
        this.UA = 0;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.Uz = a.clg().intern();
        this.UA = a.getInt();
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
        return aPw.eEG.getId();
    }
}