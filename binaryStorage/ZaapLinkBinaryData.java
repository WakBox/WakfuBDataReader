package com.ankamagames.wakfu.client.binaryStorage;

public class ZaapLinkBinaryData implements dEZ {
    protected int az;
    protected int aQP;
    protected int aQQ;
    protected int aQR;
    
    public ZaapLinkBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int getStart()
    {
        return this.aQP;
    }
    
    public int rR()
    {
        return this.aQQ;
    }
    
    public int rS()
    {
        return this.aQR;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aQP = 0;
        this.aQQ = 0;
        this.aQR = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aQP = a.getInt();
        this.aQQ = a.getInt();
        this.aQR = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eEO.getId();
    }
}