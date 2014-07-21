package com.ankamagames.wakfu.client.binaryStorage;

public class HavenBagModelViewBinaryData implements dEZ {
    protected int az;
    protected boolean dyx;
    protected boolean dyy;
    protected int dyz;
    protected boolean ciS;
    
    public HavenBagModelViewBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public boolean aAP()
    {
        return this.dyx;
    }
    
    public boolean aAQ()
    {
        return this.dyy;
    }
    
    public int aAR()
    {
        return this.dyz;
    }
    
    public boolean Zo()
    {
        return this.ciS;
    }
    
    public void reset()
    {
        this.az = 0;
        this.dyx = false;
        this.dyy = false;
        this.dyz = 0;
        this.ciS = false;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.dyx = a.readBoolean();
        this.dyy = a.readBoolean();
        this.dyz = a.getInt();
        this.ciS = a.readBoolean();
    }
    
    final public int gZ()
    {
        return aPw.eDW.getId();
    }
}