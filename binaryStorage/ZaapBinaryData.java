package com.ankamagames.wakfu.client.binaryStorage;

public class ZaapBinaryData implements dEZ {
    protected int lAr;
    protected int dpl;
    protected int dpm;
    protected int dpn;
    protected int UA;
    protected int bQK;
    protected byte fsb;
    protected boolean lAs;
    protected String lAt;
    protected com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData fEC;
    
    public ZaapBinaryData()
    {
        super();
    }
    
    public int dbo()
    {
        return this.lAr;
    }
    
    public int awa()
    {
        return this.dpl;
    }
    
    public int awb()
    {
        return this.dpm;
    }
    
    public int awc()
    {
        return this.dpn;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public int Or()
    {
        return this.bQK;
    }
    
    public byte brI()
    {
        int i = this.fsb;
        return (byte)i;
    }
    
    public boolean dbp()
    {
        return this.lAs;
    }
    
    public String dbq()
    {
        return this.lAt;
    }
    
    public com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData bwT()
    {
        return this.fEC;
    }
    
    public void reset()
    {
        this.lAr = 0;
        this.dpl = 0;
        this.dpm = 0;
        this.dpn = 0;
        this.UA = 0;
        this.bQK = 0;
        this.fsb = (byte)0;
        this.lAs = false;
        this.lAt = null;
        this.fEC = null;
    }
    
    public void a(ceb a)
    {
        this.lAr = a.getInt();
        this.dpl = a.getInt();
        this.dpm = a.getInt();
        this.dpn = a.getInt();
        this.UA = a.getInt();
        this.bQK = a.getInt();
        int i = a.get();
        this.fsb = (byte)i;
        this.lAs = a.readBoolean();
        this.lAt = a.clg().intern();
        int i0 = a.get();
        if(i0 == 0)
        {
            this.fEC = null;
        }
        else
        {
            this.fEC = new com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData();
            this.fEC.a(a);
        }
    }
    
    final public int gZ()
    {
        return aPw.eEN.getId();
    }
}