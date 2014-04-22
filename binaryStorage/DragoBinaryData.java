package com.ankamagames.wakfu.client.binaryStorage;

public class DragoBinaryData implements dEZ {
    protected int fEB;
    protected int dpl;
    protected int dpm;
    protected int UA;
    protected int bQK;
    protected byte fsb;
    protected com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData fEC;
    
    public DragoBinaryData()
    {
        super();
    }
    
    public int bwS()
    {
        return this.fEB;
    }
    
    public int awa()
    {
        return this.dpl;
    }
    
    public int awb()
    {
        return this.dpm;
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
    
    public com.ankamagames.wakfu.client.binaryStorage.TravelLoadingBinaryData bwT()
    {
        return this.fEC;
    }
    
    public void reset()
    {
        this.fEB = 0;
        this.dpl = 0;
        this.dpm = 0;
        this.UA = 0;
        this.bQK = 0;
        this.fsb = (byte)0;
        this.fEC = null;
    }
    
    public void a(ceb a)
    {
        this.fEB = a.getInt();
        this.dpl = a.getInt();
        this.dpm = a.getInt();
        this.UA = a.getInt();
        this.bQK = a.getInt();
        int i = a.get();
        this.fsb = (byte)i;
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
        return aPw.eDR.getId();
    }
}