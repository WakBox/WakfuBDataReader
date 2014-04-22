package com.ankamagames.wakfu.client.binaryStorage;

public class BoatBinaryData implements dEZ {
    protected int fsa;
    protected int dpl;
    protected int dpm;
    protected int dpn;
    protected int UA;
    protected int bQK;
    protected byte fsb;
    
    public BoatBinaryData()
    {
        super();
    }
    
    public int brH()
    {
        return this.fsa;
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
    
    public void reset()
    {
        this.fsa = 0;
        this.dpl = 0;
        this.dpm = 0;
        this.dpn = 0;
        this.UA = 0;
        this.bQK = 0;
        this.fsb = (byte)0;
    }
    
    public void a(ceb a)
    {
        this.fsa = a.getInt();
        this.dpl = a.getInt();
        this.dpm = a.getInt();
        this.dpn = a.getInt();
        this.UA = a.getInt();
        this.bQK = a.getInt();
        int i = a.get();
        this.fsb = (byte)i;
    }
    
    final public int gZ()
    {
        return aPw.eDx.getId();
    }
}