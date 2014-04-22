package com.ankamagames.wakfu.client.binaryStorage;

public class CraftInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int bPa;
    protected int iDD;
    protected int cfw;
    protected int[] iXa;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    
    public CraftInteractiveElementParamBinaryData()
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
    
    public int WV()
    {
        return this.cfw;
    }
    
    public int[] cJu()
    {
        return this.iXa;
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
        this.cfw = 0;
        this.iXa = null;
        this.UB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.bPa = a.getInt();
        this.iDD = a.getInt();
        this.cfw = a.getInt();
        this.iXa = a.cli();
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
        return aPw.eDN.getId();
    }
}