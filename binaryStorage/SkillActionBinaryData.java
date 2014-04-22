package com.ankamagames.wakfu.client.binaryStorage;

public class SkillActionBinaryData implements dEZ {
    protected int az;
    protected int brR;
    protected String brS;
    protected int[] brT;
    protected String brU;
    
    public SkillActionBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int FZ()
    {
        return this.brR;
    }
    
    public String Ga()
    {
        return this.brS;
    }
    
    public int[] Gb()
    {
        return this.brT;
    }
    
    public String Gc()
    {
        return this.brU;
    }
    
    public void reset()
    {
        this.az = 0;
        this.brR = 0;
        this.brS = null;
        this.brT = null;
        this.brU = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.brR = a.getInt();
        this.brS = a.clg().intern();
        this.brT = a.cli();
        this.brU = a.clg().intern();
    }
    
    final public int gZ()
    {
        return aPw.eEC.getId();
    }
}