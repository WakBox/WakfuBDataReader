package com.ankamagames.wakfu.client.binaryStorage;

public class ResourceBinaryData implements dEZ {
    protected int az;
    protected int aNz;
    protected short blQ;
    protected short blR;
    protected short blS;
    protected short blT;
    protected boolean blU;
    protected boolean blV;
    protected boolean blW;
    protected short blX;
    protected int[] blY;
    protected int[] blZ;
    protected bYn[] bma;
    protected short bmb;
    protected int bmc;
    protected deN bmd;
    
    public ResourceBinaryData()
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
    
    public short Dl()
    {
        int i = this.blQ;
        return (short)i;
    }
    
    public short Dm()
    {
        int i = this.blR;
        return (short)i;
    }
    
    public short Dn()
    {
        int i = this.blS;
        return (short)i;
    }
    
    public short Do()
    {
        int i = this.blT;
        return (short)i;
    }
    
    public boolean isBlocking()
    {
        return this.blU;
    }
    
    public boolean Dp()
    {
        return this.blV;
    }
    
    public boolean Dq()
    {
        return this.blW;
    }
    
    public short Dr()
    {
        int i = this.blX;
        return (short)i;
    }
    
    public int[] Ds()
    {
        return this.blY;
    }
    
    public int[] Dt()
    {
        return this.blZ;
    }
    
    public bYn[] Du()
    {
        return this.bma;
    }
    
    public short Dv()
    {
        int i = this.bmb;
        return (short)i;
    }
    
    public int Dw()
    {
        return this.bmc;
    }
    
    public deN Dx()
    {
        return this.bmd;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aNz = 0;
        this.blQ = (short)0;
        this.blR = (short)0;
        this.blS = (short)0;
        this.blT = (short)0;
        this.blU = false;
        this.blV = false;
        this.blW = false;
        this.blX = (short)0;
        this.blY = null;
        this.blZ = null;
        this.bma = null;
        this.bmb = (short)0;
        this.bmc = 0;
        this.bmd = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aNz = a.getInt();
        int i = a.getShort();
        this.blQ = (short)i;
        int i0 = a.getShort();
        this.blR = (short)i0;
        int i1 = a.getShort();
        this.blS = (short)i1;
        int i2 = a.getShort();
        this.blT = (short)i2;
        this.blU = a.readBoolean();
        this.blV = a.readBoolean();
        this.blW = a.readBoolean();
        int i3 = a.getShort();
        this.blX = (short)i3;
        this.blY = a.cli();
        this.blZ = a.cli();
        int i4 = a.getInt();
        this.bma = new bYn[i4];
        int i5 = 0;
        while(i5 < i4)
        {
            this.bma[i5] = new bYn();
            this.bma[i5].a(a);
            i5 = i5 + 1;
        }
        int i6 = a.getShort();
        this.bmb = (short)i6;
        this.bmc = a.getInt();
        int i7 = a.getInt();
        this.bmd = new deN(i7);
        int i8 = 0;
        while(i8 < i7)
        {
            int i9 = a.getInt();
            int[] a0 = a.cli();
            this.bmd.put(i9, (Object)a0);
            i8 = i8 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eEx.getId();
    }
}