package com.ankamagames.wakfu.client.binaryStorage;

public class ProtectorBinaryData implements dEZ {
    protected int aNN;
    protected int lu;
    protected int dwI;
    protected int dwJ;
    protected int dwK;
    protected int dwL;
    protected int dwM;
    protected int dwN;
    protected int dwO;
    protected int iF;
    protected int dwP;
    protected int dwQ;
    protected int dwR;
    protected int dwS;
    protected short dwT;
    protected int[] dwU;
    protected Sy[] dwV;
    protected Vf[] dwW;
    protected qL[] dwX;
    
    public ProtectorBinaryData()
    {
        super();
    }
    
    public int Et()
    {
        return this.aNN;
    }
    
    public int fp()
    {
        return this.lu;
    }
    
    public int aAa()
    {
        return this.dwI;
    }
    
    public int aAb()
    {
        return this.dwJ;
    }
    
    public int aAc()
    {
        return this.dwK;
    }
    
    public int aAd()
    {
        return this.dwL;
    }
    
    public int aAe()
    {
        return this.dwM;
    }
    
    public int aAf()
    {
        return this.dwN;
    }
    
    public int aAg()
    {
        return this.dwO;
    }
    
    public int bZ()
    {
        return this.iF;
    }
    
    public int aAh()
    {
        return this.dwP;
    }
    
    public int aAi()
    {
        return this.dwQ;
    }
    
    public int aAj()
    {
        return this.dwR;
    }
    
    public int aAk()
    {
        return this.dwS;
    }
    
    public short aAl()
    {
        int i = this.dwT;
        return (short)i;
    }
    
    public int[] aAm()
    {
        return this.dwU;
    }
    
    public Sy[] aAn()
    {
        return this.dwV;
    }
    
    public Vf[] aAo()
    {
        return this.dwW;
    }
    
    public qL[] aAp()
    {
        return this.dwX;
    }
    
    public void reset()
    {
        this.aNN = 0;
        this.lu = 0;
        this.dwI = 0;
        this.dwJ = 0;
        this.dwK = 0;
        this.dwL = 0;
        this.dwM = 0;
        this.dwN = 0;
        this.dwO = 0;
        this.iF = 0;
        this.dwP = 0;
        this.dwQ = 0;
        this.dwR = 0;
        this.dwS = 0;
        this.dwT = (short)0;
        this.dwU = null;
        this.dwV = null;
        this.dwW = null;
        this.dwX = null;
    }
    
    public void a(ceb a)
    {
        this.aNN = a.getInt();
        this.lu = a.getInt();
        this.dwI = a.getInt();
        this.dwJ = a.getInt();
        this.dwK = a.getInt();
        this.dwL = a.getInt();
        this.dwM = a.getInt();
        this.dwN = a.getInt();
        this.dwO = a.getInt();
        this.iF = a.getInt();
        this.dwP = a.getInt();
        this.dwQ = a.getInt();
        this.dwR = a.getInt();
        this.dwS = a.getInt();
        int i = a.getShort();
        this.dwT = (short)i;
        this.dwU = a.cli();
        int i0 = a.getInt();
        this.dwV = new Sy[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.dwV[i1] = new Sy();
            this.dwV[i1].a(a);
            i1 = i1 + 1;
        }
        int i2 = a.getInt();
        this.dwW = new Vf[i2];
        int i3 = 0;
        while(i3 < i2)
        {
            this.dwW[i3] = new Vf();
            this.dwW[i3].a(a);
            i3 = i3 + 1;
        }
        int i4 = a.getInt();
        this.dwX = new qL[i4];
        int i5 = 0;
        while(i5 < i4)
        {
            this.dwX[i5] = new qL();
            this.dwX[i5].a(a);
            i5 = i5 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eEr.getId();
    }
}