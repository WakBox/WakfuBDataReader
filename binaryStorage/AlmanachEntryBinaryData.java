package com.ankamagames.wakfu.client.binaryStorage;

public class AlmanachEntryBinaryData implements dEZ {
    protected int az;
    protected int aVd;
    protected int aWx;
    protected int[] htU;
    
    public AlmanachEntryBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int tb()
    {
        return this.aVd;
    }
    
    public int tV()
    {
        return this.aWx;
    }
    
    public int[] ceZ()
    {
        return this.htU;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aVd = 0;
        this.aWx = 0;
        this.htU = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aVd = a.getInt();
        this.aWx = a.getInt();
        this.htU = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eFj.getId();
    }
}