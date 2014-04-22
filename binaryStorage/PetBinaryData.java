package com.ankamagames.wakfu.client.binaryStorage;

public class PetBinaryData implements dEZ {
    protected int az;
    protected int dWn;
    protected int aZE;
    protected int dWo;
    protected int bED;
    protected long dWp;
    protected long dWq;
    protected byte dWr;
    protected short dWs;
    protected short dbB;
    protected bTO[] dWt;
    protected dHC[] dWu;
    protected dXF[] dWv;
    protected dAX[] dWw;
    protected int[] dWx;
    protected aBK[] dWy;
    
    public PetBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int aKL()
    {
        return this.dWn;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public int aKM()
    {
        return this.dWo;
    }
    
    public int aKN()
    {
        return this.bED;
    }
    
    public long aKO()
    {
        return this.dWp;
    }
    
    public long aKP()
    {
        return this.dWq;
    }
    
    public byte aKQ()
    {
        int i = this.dWr;
        return (byte)i;
    }
    
    public short aKR()
    {
        int i = this.dWs;
        return (short)i;
    }
    
    public short apD()
    {
        int i = this.dbB;
        return (short)i;
    }
    
    public bTO[] aKS()
    {
        return this.dWt;
    }
    
    public dHC[] aKT()
    {
        return this.dWu;
    }
    
    public dXF[] aKU()
    {
        return this.dWv;
    }
    
    public dAX[] aKV()
    {
        return this.dWw;
    }
    
    public int[] aKW()
    {
        return this.dWx;
    }
    
    public aBK[] aKX()
    {
        return this.dWy;
    }
    
    public void reset()
    {
        this.az = 0;
        this.dWn = 0;
        this.aZE = 0;
        this.dWo = 0;
        this.bED = 0;
        this.dWp = 0L;
        this.dWq = 0L;
        this.dWr = (byte)0;
        this.dWs = (short)0;
        this.dbB = (short)0;
        this.dWt = null;
        this.dWu = null;
        this.dWv = null;
        this.dWw = null;
        this.dWx = null;
        this.dWy = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.dWn = a.getInt();
        this.aZE = a.getInt();
        this.dWo = a.getInt();
        this.bED = a.getInt();
        this.dWp = a.getLong();
        this.dWq = a.getLong();
        int i = a.get();
        this.dWr = (byte)i;
        int i0 = a.getShort();
        this.dWs = (short)i0;
        int i1 = a.getShort();
        this.dbB = (short)i1;
        int i2 = a.getInt();
        this.dWt = new bTO[i2];
        int i3 = 0;
        while(i3 < i2)
        {
            this.dWt[i3] = new bTO();
            this.dWt[i3].a(a);
            i3 = i3 + 1;
        }
        int i4 = a.getInt();
        this.dWu = new dHC[i4];
        int i5 = 0;
        while(i5 < i4)
        {
            this.dWu[i5] = new dHC();
            this.dWu[i5].a(a);
            i5 = i5 + 1;
        }
        int i6 = a.getInt();
        this.dWv = new dXF[i6];
        int i7 = 0;
        while(i7 < i6)
        {
            this.dWv[i7] = new dXF();
            this.dWv[i7].a(a);
            i7 = i7 + 1;
        }
        int i8 = a.getInt();
        this.dWw = new dAX[i8];
        int i9 = 0;
        while(i9 < i8)
        {
            this.dWw[i9] = new dAX();
            this.dWw[i9].a(a);
            i9 = i9 + 1;
        }
        this.dWx = a.cli();
        int i10 = a.getInt();
        this.dWy = new aBK[i10];
        int i11 = 0;
        while(i11 < i10)
        {
            this.dWy[i11] = new aBK();
            this.dWy[i11].a(a);
            i11 = i11 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFC.getId();
    }
}