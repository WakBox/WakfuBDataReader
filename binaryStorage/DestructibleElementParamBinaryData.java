package com.ankamagames.wakfu.client.binaryStorage;

public class DestructibleElementParamBinaryData implements dEZ {
    protected int az;
    protected int dpI;
    protected int dpJ;
    protected int dpK;
    protected int dpL;
    protected int dpM;
    protected int dpN;
    protected int[] bav;
    
    public DestructibleElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int awt()
    {
        return this.dpI;
    }
    
    public int awu()
    {
        return this.dpJ;
    }
    
    public int awv()
    {
        return this.dpK;
    }
    
    public int aww()
    {
        return this.dpL;
    }
    
    public int awx()
    {
        return this.dpM;
    }
    
    public int awy()
    {
        return this.dpN;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public void reset()
    {
        this.az = 0;
        this.dpI = 0;
        this.dpJ = 0;
        this.dpK = 0;
        this.dpL = 0;
        this.dpM = 0;
        this.dpN = 0;
        this.bav = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.dpI = a.getInt();
        this.dpJ = a.getInt();
        this.dpK = a.getInt();
        this.dpL = a.getInt();
        this.dpM = a.getInt();
        this.dpN = a.getInt();
        this.bav = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eDP.getId();
    }
}