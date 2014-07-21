package com.ankamagames.wakfu.client.binaryStorage;

public class SkillBinaryData implements dEZ {
    protected int az;
    protected int aNz;
    protected int aZD;
    protected int brR;
    protected String brS;
    protected String brU;
    protected int[] cly;
    protected int[] brT;
    protected int ciR;
    protected boolean clz;
    
    public SkillBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int getType()
    {
        return this.aNz;
    }
    
    public int vU()
    {
        return this.aZD;
    }
    
    public int FZ()
    {
        return this.brR;
    }
    
    public String Ga()
    {
        return this.brS;
    }
    
    public String Gc()
    {
        return this.brU;
    }
    
    public int[] aay()
    {
        return this.cly;
    }
    
    public int[] Gb()
    {
        return this.brT;
    }
    
    public int Sr()
    {
        return this.ciR;
    }
    
    public boolean Zo()
    {
        return this.clz;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aNz = 0;
        this.aZD = 0;
        this.brR = 0;
        this.brS = null;
        this.brU = null;
        this.cly = null;
        this.brT = null;
        this.ciR = 0;
        this.clz = false;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aNz = a.getInt();
        this.aZD = a.getInt();
        this.brR = a.getInt();
        this.brS = a.clg().intern();
        this.brU = a.clg().intern();
        this.cly = a.cli();
        this.brT = a.cli();
        this.ciR = a.getInt();
        this.clz = a.readBoolean();
    }
    
    final public int gZ()
    {
        return aPw.eEB.getId();
    }
}