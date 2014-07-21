package com.ankamagames.wakfu.client.binaryStorage;

public class InteractiveElementTemplateBinaryData implements dEZ {
    protected int az;
    protected short iEf;
    protected short aC;
    protected int iA;
    protected int iB;
    protected short aVB;
    protected short iDi;
    protected boolean iDj;
    protected boolean iDk;
    protected boolean fBs;
    protected boolean iDl;
    protected byte bxt;
    protected short fCE;
    protected String fCG;
    protected int bGs;
    protected int[] blY;
    protected Hd[] iEg;
    protected MU iEh;
    protected int[] gky;
    
    public InteractiveElementTemplateBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short cBp()
    {
        int i = this.iEf;
        return (short)i;
    }
    
    public short D()
    {
        int i = this.aC;
        return (short)i;
    }
    
    public int getX()
    {
        return this.iA;
    }
    
    public int getY()
    {
        return this.iB;
    }
    
    public short KL()
    {
        int i = this.aVB;
        return (short)i;
    }
    
    public short cBq()
    {
        int i = this.iDi;
        return (short)i;
    }
    
    public boolean cBr()
    {
        return this.iDj;
    }
    
    public boolean cBs()
    {
        return this.iDk;
    }
    
    public boolean aid()
    {
        return this.fBs;
    }
    
    public boolean cBt()
    {
        return this.iDl;
    }
    
    public byte HY()
    {
        int i = this.bxt;
        return (byte)i;
    }
    
    public short bwk()
    {
        int i = this.fCE;
        return (short)i;
    }
    
    public String cBu()
    {
        return this.fCG;
    }
    
    public int asW()
    {
        return this.bGs;
    }
    
    public int[] Ds()
    {
        return this.blY;
    }
    
    public Hd[] cBv()
    {
        return this.iEg;
    }
    
    public MU cBw()
    {
        return this.iEh;
    }
    
    public int[] cBx()
    {
        return this.gky;
    }
    
    public void reset()
    {
        this.az = 0;
        this.iEf = (short)0;
        this.aC = (short)0;
        this.iA = 0;
        this.iB = 0;
        this.aVB = (short)0;
        this.iDi = (short)0;
        this.iDj = false;
        this.iDk = false;
        this.fBs = false;
        this.iDl = false;
        this.bxt = (byte)0;
        this.fCE = (short)0;
        this.fCG = null;
        this.bGs = 0;
        this.blY = null;
        this.iEg = null;
        this.iEh = null;
        this.gky = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.iEf = (short)i;
        int i0 = a.getShort();
        this.aC = (short)i0;
        this.iA = a.getInt();
        this.iB = a.getInt();
        int i1 = a.getShort();
        this.aVB = (short)i1;
        int i2 = a.getShort();
        this.iDi = (short)i2;
        this.iDj = a.readBoolean();
        this.iDk = a.readBoolean();
        this.fBs = a.readBoolean();
        this.iDl = a.readBoolean();
        int i3 = a.get();
        this.bxt = (byte)i3;
        int i4 = a.getShort();
        this.fCE = (short)i4;
        
        this.fCG = a.clg().intern();
        this.bGs = a.getInt();
        this.blY = a.cli();
        int i5 = a.getInt();
        
        
        this.iEg = new Hd[i5];
        int i6 = 0;
        while(i6 < i5)
        {
            this.iEg[i6] = new Hd();
            this.iEg[i6].a(a);
            i6 = i6 + 1;
        }
        int i7 = a.getInt();
        this.iEh = new MU(i7);
        int i8 = 0;
        while(i8 < i7)
        {
            int i9 = a.getShort();
            int i10 = a.getInt();
            this.iEh.a((short)i9, i10);
            i8 = i8 + 1;
        }
        this.gky = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eFN.getId();
    }
}