package com.ankamagames.wakfu.client.binaryStorage;

public class StorageBoxBinaryData implements dEZ {
    protected int az;
    protected int UA;
    protected com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData UB;
    protected Vl[] eOd;
    
    public StorageBoxBinaryData()
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
    
    public com.ankamagames.wakfu.client.binaryStorage.ChaosParamBinaryData gY()
    {
        return this.UB;
    }
    
    public Vl[] bmt()
    {
        return this.eOd;
    }
    
    public void reset()
    {
        this.az = 0;
        this.UA = 0;
        this.UB = null;
        this.eOd = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
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
        int i0 = a.getInt();
        this.eOd = new Vl[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.eOd[i1] = new Vl();
            this.eOd[i1].a(a);
            i1 = i1 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eEH.getId();
    }
}