package com.ankamagames.wakfu.client.binaryStorage;

public class RecipeBinaryData implements dEZ {
    protected int az;
    protected int exW;
    protected long cIb;
    protected String aZr;
    protected String jjk;
    protected int aPT;
    protected int[] blY;
    protected int jgs;
    protected int[] jjl;
    protected int jjm;
    protected boolean jjn;
    protected long jjo;
    protected long ean;
    protected qQ[] jjp;
    protected ccU[] jjq;
    protected dZl[] jjr;
    
    public RecipeBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int aZb()
    {
        return this.exW;
    }
    
    public long getDuration()
    {
        return this.cIb;
    }
    
    public String vS()
    {
        return this.aZr;
    }
    
    public String cOQ()
    {
        return this.jjk;
    }
    
    public int getLevel()
    {
        return this.aPT;
    }
    
    public int[] Ds()
    {
        return this.blY;
    }
    
    public int cNF()
    {
        return this.jgs;
    }
    
    public int[] cOR()
    {
        return this.jjl;
    }
    
    public int cOS()
    {
        return this.jjm;
    }
    
    public boolean cOT()
    {
        return this.jjn;
    }
    
    public long cOU()
    {
        return this.jjo;
    }
    
    public long aDw()
    {
        return this.ean;
    }
    
    public qQ[] cOV()
    {
        return this.jjp;
    }
    
    public ccU[] cOW()
    {
        return this.jjq;
    }
    
    public dZl[] cOX()
    {
        return this.jjr;
    }
    
    public void reset()
    {
        this.az = 0;
        this.exW = 0;
        this.cIb = 0L;
        this.aZr = null;
        this.jjk = null;
        this.aPT = 0;
        this.blY = null;
        this.jgs = 0;
        this.jjl = null;
        this.jjm = 0;
        this.jjn = false;
        this.jjo = 0L;
        this.ean = 0L;
        this.jjp = null;
        this.jjq = null;
        this.jjr = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.exW = a.getInt();
        this.cIb = a.getLong();
        this.aZr = a.clg().intern();
        this.jjk = a.clg().intern();
        this.aPT = a.getInt();
        this.blY = a.cli();
        this.jgs = a.getInt();
        this.jjl = a.cli();
        this.jjm = a.getInt();
        this.jjn = a.readBoolean();
        this.jjo = a.getLong();
        this.ean = a.getLong();
        int i = a.getInt();
        this.jjp = new qQ[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.jjp[i0] = new qQ();
            this.jjp[i0].a(a);
            i0 = i0 + 1;
        }
        int i1 = a.getInt();
        this.jjq = new ccU[i1];
        int i2 = 0;
        while(i2 < i1)
        {
            this.jjq[i2] = new ccU();
            this.jjq[i2].a(a);
            i2 = i2 + 1;
        }
        int i3 = a.getInt();
        this.jjr = new dZl[i3];
        int i4 = 0;
        while(i4 < i3)
        {
            this.jjr[i4] = new dZl();
            this.jjr[i4].a(a);
            i4 = i4 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eEv.getId();
    }
}