package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldBuildingBinaryData implements dEZ {
    protected int az;
    protected short hvt;
    protected int cMg;
    protected int hGe;
    protected byte hGf;
    protected byte dPI;
    protected int hGg;
    protected boolean fYf;
    protected cEb[] hGh;
    protected cqf[] hGi;
    protected int[] bav;
    protected YV[] hGj;
    
    public HavenWorldBuildingBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short cfA()
    {
        int i = this.hvt;
        return (short)i;
    }
    
    public int alf()
    {
        return this.cMg;
    }
    
    public int cjP()
    {
        return this.hGe;
    }
    
    public byte cjQ()
    {
        int i = this.hGf;
        return (byte)i;
    }
    
    public byte aIi()
    {
        int i = this.dPI;
        return (byte)i;
    }
    
    public int bjU()
    {
        return this.hGg;
    }
    
    public boolean bDV()
    {
        return this.fYf;
    }
    
    public cEb[] cjR()
    {
        return this.hGh;
    }
    
    public cqf[] cjS()
    {
        return this.hGi;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public YV[] cjT()
    {
        return this.hGj;
    }
    
    public void reset()
    {
        this.az = 0;
        this.hvt = (short)0;
        this.cMg = 0;
        this.hGe = 0;
        this.hGf = (byte)0;
        this.dPI = (byte)0;
        this.hGg = 0;
        this.fYf = false;
        this.hGh = null;
        this.hGi = null;
        this.bav = null;
        this.hGj = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.hvt = (short)i;
        this.cMg = a.getInt();
        this.hGe = a.getInt();
        int i0 = a.get();
        this.hGf = (byte)i0;
        int i1 = a.get();
        this.dPI = (byte)i1;
        this.hGg = a.getInt();
        this.fYf = a.readBoolean();
        int i2 = a.getInt();
        this.hGh = new cEb[i2];
        int i3 = 0;
        while(i3 < i2)
        {
            this.hGh[i3] = new cEb();
            this.hGh[i3].a(a);
            i3 = i3 + 1;
        }
        int i4 = a.getInt();
        this.hGi = new cqf[i4];
        int i5 = 0;
        while(i5 < i4)
        {
            this.hGi[i5] = new cqf();
            this.hGi[i5].a(a);
            i5 = i5 + 1;
        }
        this.bav = a.cli();
        int i6 = a.getInt();
        this.hGj = new YV[i6];
        int i7 = 0;
        while(i7 < i6)
        {
            this.hGj[i7] = new YV();
            this.hGj[i7].a(a);
            i7 = i7 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFn.getId();
    }
}