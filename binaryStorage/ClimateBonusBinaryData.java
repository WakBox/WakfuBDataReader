package com.ankamagames.wakfu.client.binaryStorage;

public class ClimateBonusBinaryData implements dEZ {
    protected int cAA;
    protected int aZE;
    protected String aZr;
    protected int aSf;
    protected short fYv;
    protected float fYw;
    protected float fYx;
    protected float fYy;
    
    public ClimateBonusBinaryData()
    {
        super();
    }
    
    public int afp()
    {
        return this.cAA;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public String vS()
    {
        return this.aZr;
    }
    
    public int getDuration()
    {
        return this.aSf;
    }
    
    public short bEi()
    {
        int i = this.fYv;
        return (short)i;
    }
    
    public float bEj()
    {
        return this.fYw;
    }
    
    public float bEk()
    {
        return this.fYx;
    }
    
    public float bEl()
    {
        return this.fYy;
    }
    
    public void reset()
    {
        this.cAA = 0;
        this.aZE = 0;
        this.aZr = null;
        this.aSf = 0;
        this.fYv = (short)0;
        this.fYw = 0.0f;
        this.fYx = 0.0f;
        this.fYy = 0.0f;
    }
    
    public void a(ceb a)
    {
        this.cAA = a.getInt();
        this.aZE = a.getInt();
        this.aZr = a.clg().intern();
        this.aSf = a.getInt();
        int i = a.getShort();
        this.fYv = (short)i;
        this.fYw = a.getFloat();
        this.fYx = a.getFloat();
        this.fYy = a.getFloat();
    }
    
    final public int gZ()
    {
        return aPw.eDJ.getId();
    }
}