package com.ankamagames.wakfu.client.binaryStorage;

public class ExchangeInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int bPa;
    protected int iDD;
    protected byte jmN;
    protected aMa[] jmO;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public ExchangeInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int NX()
    {
        return this.bPa;
    }
    
    public int cBc()
    {
        return this.iDD;
    }
    
    public byte cQE()
    {
        int i = this.jmN;
        return (byte)i;
    }
    
    public aMa[] cQF()
    {
        return this.jmO;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bPa = 0;
        this.iDD = 0;
        this.jmN = (byte)0;
        this.jmO = null;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.bPa = a.getInt();
        this.iDD = a.getInt();
        int i = a.get();
        this.jmN = (byte)i;
        int i0 = a.getInt();
        this.jmO = new aMa[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.jmO[i1] = new aMa();
            this.jmO[i1].a(a);
            i1 = i1 + 1;
        }
        int i2 = a.get();
        if(i2 == 0)
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
        return aPw.eET.getId();
    }
}