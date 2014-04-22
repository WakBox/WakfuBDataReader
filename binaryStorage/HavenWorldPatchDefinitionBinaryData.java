package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldPatchDefinitionBinaryData implements dEZ {
    protected int az;
    protected int hsI;
    protected int cMg;
    protected int exW;
    protected int hJ;
    
    public HavenWorldPatchDefinitionBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int cez()
    {
        return this.hsI;
    }
    
    public int alf()
    {
        return this.cMg;
    }
    
    public int aZb()
    {
        return this.exW;
    }
    
    public int getSoundId()
    {
        return this.hJ;
    }
    
    public void reset()
    {
        this.az = 0;
        this.hsI = 0;
        this.cMg = 0;
        this.exW = 0;
        this.hJ = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.hsI = a.getInt();
        this.cMg = a.getInt();
        this.exW = a.getInt();
        this.hJ = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eFm.getId();
    }
}