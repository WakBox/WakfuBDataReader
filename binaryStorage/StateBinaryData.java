package com.ankamagames.wakfu.client.binaryStorage;

public class StateBinaryData implements dEZ {
    protected int az;
    protected short aZF;
    protected int[] bUE;
    protected int[] bUF;
    protected float[] bUG;
    protected boolean aVU;
    protected boolean aVT;
    protected boolean bUH;
    protected boolean bUI;
    protected boolean bUJ;
    protected String bUK;
    protected String bUL;
    protected boolean bUM;
    protected boolean bjt;
    protected int[] bav;
    protected int[] bUN;
    protected boolean bUO;
    protected boolean bUP;
    protected byte bUQ;
    protected byte bUR;
    protected boolean bUS;
    protected boolean bUT;
    protected int aZE;
    protected boolean bUU;
    
    public StateBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short oE()
    {
        int i = this.aZF;
        return (short)i;
    }
    
    public int[] Qc()
    {
        return this.bUE;
    }
    
    public int[] Qd()
    {
        return this.bUF;
    }
    
    public float[] Qe()
    {
        return this.bUG;
    }
    
    public short Qf()
    {
        int i = (short)this.bUF[0];
        return (short)i;
    }
    
    public int Qg()
    {
        return (this.bUF.length != 0) ? 1000 * this.bUF[1] : 0;
    }
    
    public float Qh()
    {
        return this.bUG[0];
    }
    
    public int Qi()
    {
        return (this.bUG.length != 0) ? (int)(1000f * this.bUG[1]) : 0;
    }
    
    public boolean AY()
    {
        return this.aVU;
    }
    
    public boolean AZ()
    {
        return this.aVT;
    }
    
    public boolean BF()
    {
        return this.bUH;
    }
    
    public boolean Qj()
    {
        return this.bUI;
    }
    
    public boolean Qk()
    {
        return this.bUJ;
    }
    
    public String Ql()
    {
        return this.bUK;
    }
    
    public String Qm()
    {
        return this.bUL;
    }
    
    public boolean Qn()
    {
        return this.bUM;
    }
    
    public boolean BA()
    {
        return this.bjt;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public int[] Qo()
    {
        return this.bUN;
    }
    
    public boolean Qp()
    {
        return this.bUO;
    }
    
    public boolean Bv()
    {
        return this.bUP;
    }
    
    public byte Qq()
    {
        int i = this.bUQ;
        return (byte)i;
    }
    
    public byte Qr()
    {
        int i = this.bUR;
        return (byte)i;
    }
    
    public boolean Qs()
    {
        return this.bUS;
    }
    
    public boolean Qt()
    {
        return this.bUT;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public boolean Qu()
    {
        return this.bUU;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aZF = (short)0;
        this.bUE = null;
        this.bUF = null;
        this.bUG = null;
        this.aVU = false;
        this.aVT = false;
        this.bUH = false;
        this.bUI = false;
        this.bUJ = false;
        this.bUK = null;
        this.bUL = null;
        this.bUM = false;
        this.bjt = false;
        this.bav = null;
        this.bUN = null;
        this.bUO = false;
        this.bUP = false;
        this.bUQ = (byte)0;
        this.bUR = (byte)0;
        this.bUS = false;
        this.bUT = false;
        this.aZE = 0;
        this.bUU = false;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.aZF = (short)i;
        this.bUE = a.cli();
        this.bUF = a.cli();
        this.bUG = a.clk();
        this.aVU = a.readBoolean();
        this.aVT = a.readBoolean();
        this.bUH = a.readBoolean();
        this.bUI = a.readBoolean();
        this.bUJ = a.readBoolean();
        this.bUK = a.clg().intern();
        this.bUL = a.clg().intern();
        this.bUM = a.readBoolean();
        this.bjt = a.readBoolean();
        this.bav = a.cli();
        this.bUN = a.cli();
        this.bUO = a.readBoolean();
        this.bUP = a.readBoolean();
        int i0 = a.get();
        this.bUQ = (byte)i0;
        int i1 = a.get();
        this.bUR = (byte)i1;
        this.bUS = a.readBoolean();
        this.bUT = a.readBoolean();
        this.aZE = a.getInt();
        this.bUU = a.readBoolean();
    }
    
    final public int gZ()
    {
        return aPw.eEE.getId();
    }
}