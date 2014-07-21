package com.ankamagames.wakfu.client.binaryStorage;

public class TreasureBinaryData implements dEZ {
    protected int az;
    protected int ecK;
    protected int ecL;
    protected short aMk;
    protected int ecM;
    protected int ecN;
    protected int aSf;
    protected String Uz;
    protected float lgR;
    
    public TreasureBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int aNh()
    {
        return this.ecK;
    }
    
    public int aNi()
    {
        return this.ecL;
    }
    
    public short oy()
    {
        int i = this.aMk;
        return (short)i;
    }
    
    public int aNj()
    {
        return this.ecM;
    }
    
    public int aNk()
    {
        return this.ecN;
    }
    
    public int getDuration()
    {
        return this.aSf;
    }
    
    public String gW()
    {
        return this.Uz;
    }
    
    public float cUz()
    {
        return this.lgR;
    }
    
    public void reset()
    {
        this.az = 0;
        this.ecK = 0;
        this.ecL = 0;
        this.aMk = (short)0;
        this.ecM = 0;
        this.ecN = 0;
        this.aSf = 0;
        this.Uz = null;
        this.lgR = 0.0f;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.ecK = a.getInt();
        this.ecL = a.getInt();
        int i = a.getShort();
        this.aMk = (short)i;
        this.ecM = a.getInt();
        this.ecN = a.getInt();
        this.aSf = a.getInt();
        this.Uz = a.clg().intern();
        this.lgR = a.getFloat();
    }
    
    final public int gZ()
    {
        return aPw.eFH.getId();
    }
}