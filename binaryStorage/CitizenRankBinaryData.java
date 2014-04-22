package com.ankamagames.wakfu.client.binaryStorage;

public class CitizenRankBinaryData implements dEZ {
    protected int az;
    protected int cIj;
    protected int drT;
    protected String drU;
    protected String drV;
    protected int[] lhj;
    
    public CitizenRankBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int ajF()
    {
        return this.cIj;
    }
    
    public int ajG()
    {
        return this.drT;
    }
    
    public String ajE()
    {
        return this.drU;
    }
    
    public String getColor()
    {
        return this.drV;
    }
    
    public int[] cUJ()
    {
        return this.lhj;
    }
    
    public aWJ[] cUK()
    {
        aWJ[] a = new aWJ[this.lhj.length];
        int i = 0;
        while(i < this.lhj.length)
        {
            a[i] = aWJ.oN(this.lhj[i]);
            i = i + 1;
        }
        return a;
    }
    
    public void reset()
    {
        this.az = 0;
        this.cIj = 0;
        this.drT = 0;
        this.drU = null;
        this.drV = null;
        this.lhj = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.cIj = a.getInt();
        this.drT = a.getInt();
        this.drU = a.clg().intern();
        this.drV = a.clg().intern();
        this.lhj = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eDG.getId();
    }
}