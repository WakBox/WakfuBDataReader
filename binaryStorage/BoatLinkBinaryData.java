package com.ankamagames.wakfu.client.binaryStorage;

public class BoatLinkBinaryData implements dEZ {
    protected int az;
    protected int aQP;
    protected int aQQ;
    protected int aQR;
    protected String aZr;
    protected String moH;
    protected boolean lcN;
    protected com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData fEC;
    
    public BoatLinkBinaryData()
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
    
    public String vS()
    {
        return this.aZr;
    }
    
    public String dsE()
    {
        return this.moH;
    }
    
    public boolean cTI()
    {
        return this.lcN;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData bwT()
    {
        return this.fEC;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aQP = 0;
        this.aQQ = 0;
        this.aQR = 0;
        this.aZr = null;
        this.moH = null;
        this.lcN = false;
        this.fEC = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aQP = a.getInt();
        this.aQQ = a.getInt();
        this.aQR = a.getInt();
        this.aZr = a.clg().intern();
        this.moH = a.clg().intern();
        this.lcN = a.readBoolean();
        this.fEC = new com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData();
        this.fEC.a(a);
    }
    
    final public int gZ()
    {
        return aPw.eDy.getId();
    }
}