package com.ankamagames.wakfu.client.binaryStorage;

public class MarketBoardInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int iDD;
    protected int dyM;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public MarketBoardInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int cBc()
    {
        return this.iDD;
    }
    
    public int aBz()
    {
        return this.dyM;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.iDD = 0;
        this.dyM = 0;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.iDD = a.getInt();
        this.dyM = a.getInt();
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
        return aPw.eEe.getId();
    }
}