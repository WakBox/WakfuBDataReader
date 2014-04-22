package com.ankamagames.wakfu.client.binaryStorage;

public class ItemBinaryData implements dEZ {
    protected int az;
    protected int gTy;
    protected short buU;
    protected int aZE;
    protected int gTb;
    protected int gTc;
    protected short bjI;
    protected String[] nbp;
    protected int nbq;
    protected short nbr;
    protected byte gTi;
    protected byte gTj;
    protected byte nbs;
    protected int gTl;
    protected int gTm;
    protected boolean gTn;
    protected boolean gTo;
    protected boolean nbt;
    protected boolean nbu;
    protected short nbv;
    protected byte nbw;
    protected String nbx;
    protected int[] nby;
    protected byte nbz;
    protected byte nbA;
    protected byte nbB;
    protected byte nbC;
    protected int[] bav;
    protected eiV[] nbD;
    protected int[] nbE;
    protected byte[] nbF;
    protected byte[] nbG;
    
    public ItemBinaryData()
    {
        super();
    }
    
    public boolean dJw()
    {
        return this.gTy == this.az;
    }
    
    public boolean dJx()
    {
        boolean b = false;
        int i = this.gTy;
        label0: {
            label1: {
                label2: {
                    if(i <= 0)
                    {
                        break label2;
                    }
                    if(this.gTy != this.az)
                    {
                        break label1;
                    }
                }
                b = false;
                break label0;
            }
            b = true;
        }
        return b;
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int bTQ()
    {
        return this.gTy;
    }
    
    public short HE()
    {
        int i = this.buU;
        return (short)i;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public int oN()
    {
        return this.gTb;
    }
    
    public int oO()
    {
        return this.gTc;
    }
    
    public short oD()
    {
        int i = this.bjI;
        return (short)i;
    }
    
    public String[] dJy()
    {
        return this.nbp;
    }
    
    public int dJz()
    {
        return this.nbq;
    }
    
    public short dJA()
    {
        int i = this.nbr;
        return (short)i;
    }
    
    public byte dJB()
    {
        int i = this.gTi;
        return (byte)i;
    }
    
    public byte dJC()
    {
        int i = this.gTj;
        return (byte)i;
    }
    
    public byte dJD()
    {
        int i = this.nbs;
        return (byte)i;
    }
    
    public int bTB()
    {
        return this.gTl;
    }
    
    public int bTA()
    {
        return this.gTm;
    }
    
    public boolean dJE()
    {
        return this.gTn;
    }
    
    public boolean dJF()
    {
        return this.gTo;
    }
    
    public boolean dJG()
    {
        return this.nbt;
    }
    
    public boolean dJH()
    {
        return this.nbu;
    }
    
    public short dJI()
    {
        int i = this.nbv;
        return (short)i;
    }
    
    public byte dJJ()
    {
        int i = this.nbw;
        return (byte)i;
    }
    
    public String dJK()
    {
        return this.nbx;
    }
    
    public int[] dJL()
    {
        return this.nby;
    }
    
    public byte dJM()
    {
        int i = this.nbz;
        return (byte)i;
    }
    
    public byte dJN()
    {
        int i = this.nbA;
        return (byte)i;
    }
    
    public byte dJO()
    {
        int i = this.nbB;
        return (byte)i;
    }
    
    public byte dJP()
    {
        int i = this.nbC;
        return (byte)i;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public eiV[] dJQ()
    {
        return this.nbD;
    }
    
    public int[] dJR()
    {
        return this.nbE;
    }
    
    public byte[] dJS()
    {
        return this.nbF;
    }
    
    public byte[] dJT()
    {
        return this.nbG;
    }
    
    public void reset()
    {
        this.az = 0;
        this.gTy = 0;
        this.buU = (short)0;
        this.aZE = 0;
        this.gTb = 0;
        this.gTc = 0;
        this.bjI = (short)0;
        this.nbp = null;
        this.nbq = 0;
        this.nbr = (short)0;
        this.gTi = (byte)0;
        this.gTj = (byte)0;
        this.nbs = (byte)0;
        this.gTl = 0;
        this.gTm = 0;
        this.gTn = false;
        this.gTo = false;
        this.nbt = false;
        this.nbu = false;
        this.nbv = (short)0;
        this.nbw = (byte)0;
        this.nbx = null;
        this.nby = null;
        this.nbz = (byte)0;
        this.nbA = (byte)0;
        this.nbB = (byte)0;
        this.nbC = (byte)0;
        this.bav = null;
        this.nbD = null;
        this.nbE = null;
        this.nbF = null;
        this.nbG = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.gTy = a.getInt();
        int i = a.getShort();
        this.buU = (short)i;
        this.aZE = a.getInt();
        this.gTb = a.getInt();
        this.gTc = a.getInt();
        int i0 = a.getShort();
        this.bjI = (short)i0;
        this.nbp = a.cll();
        this.nbq = a.getInt();
        int i1 = a.getShort();
        this.nbr = (short)i1;
        int i2 = a.get();
        this.gTi = (byte)i2;
        int i3 = a.get();
        this.gTj = (byte)i3;
        int i4 = a.get();
        this.nbs = (byte)i4;
        this.gTl = a.getInt();
        this.gTm = a.getInt();
        this.gTn = a.readBoolean();
        this.gTo = a.readBoolean();
        this.nbt = a.readBoolean();
        this.nbu = a.readBoolean();
        int i5 = a.getShort();
        this.nbv = (short)i5;
        int i6 = a.get();
        this.nbw = (byte)i6;
        this.nbx = a.clg().intern();
        this.nby = a.cli();
        int i7 = a.get();
        this.nbz = (byte)i7;
        int i8 = a.get();
        this.nbA = (byte)i8;
        int i9 = a.get();
        this.nbB = (byte)i9;
        int i10 = a.get();
        this.nbC = (byte)i10;
        this.bav = a.cli();
        int i11 = a.getInt();
        this.nbD = new eiV[i11];
        int i12 = 0;
        while(i12 < i11)
        {
            this.nbD[i12] = new eiV();
            this.nbD[i12].a(a);
            i12 = i12 + 1;
        }
        this.nbE = a.cli();
        this.nbF = a.clh();
        this.nbG = a.clh();
    }
    
    final public int gZ()
    {
        return aPw.eDY.getId();
    }
}