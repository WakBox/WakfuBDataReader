package com.ankamagames.wakfu.client.binaryStorage;

public class GenericActivableInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected apE[] cTL;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public GenericActivableInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public apE[] amG()
    {
        return this.cTL;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.cTL = null;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getInt();
        this.cTL = new apE[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.cTL[i0] = new apE();
            this.cTL[i0].a(a);
            i0 = i0 + 1;
        }
        int i1 = a.get();
        if(i1 == 0)
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
        return aPw.eDU.getId();
    }
}