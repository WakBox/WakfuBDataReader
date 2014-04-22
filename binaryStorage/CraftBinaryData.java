package com.ankamagames.wakfu.client.binaryStorage;

public class CraftBinaryData implements dEZ {
    protected int aOs;
    protected int lqH;
    protected float fNV;
    protected boolean ciS;
    protected boolean lqI;
    protected boolean lqJ;
    
    public CraftBinaryData()
    {
        super();
    }
    
    public int aCw()
    {
        return this.aOs;
    }
    
    public int cYV()
    {
        return this.lqH;
    }
    
    public float bIW()
    {
        return this.fNV;
    }
    
    public boolean Zo()
    {
        return this.ciS;
    }
    
    public boolean cYW()
    {
        return this.lqI;
    }
    
    public boolean cYX()
    {
        return this.lqJ;
    }
    
    public void reset()
    {
        this.aOs = 0;
        this.lqH = 0;
        this.fNV = 0.0f;
        this.ciS = false;
        this.lqI = false;
        this.lqJ = false;
    }
    
    public void a(ceb a)
    {
        this.aOs = a.getInt();
        this.lqH = a.getInt();
        this.fNV = a.getFloat();
        this.ciS = a.readBoolean();
        this.lqI = a.readBoolean();
        this.lqJ = a.readBoolean();
    }
    
    final public int gZ()
    {
        return aPw.eDM.getId();
    }
}