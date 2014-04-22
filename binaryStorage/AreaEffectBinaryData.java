package com.ankamagames.wakfu.client.binaryStorage;

public class AreaEffectBinaryData implements dEZ {
    protected int az;
    protected int aZD;
    protected int fXZ;
    protected int fss;
    protected int fYa;
    protected boolean fYb;
    protected boolean fYc;
    protected boolean fYd;
    protected boolean fYe;
    protected boolean fYf;
    protected String Vq;
    protected int[] fYg;
    protected int[] fYh;
    protected int[] fYi;
    protected int[] fYj;
    protected float[] fYk;
    protected float[] biV;
    protected int[] blY;
    protected int[] bav;
    protected String fYl;
    protected String fYm;
    protected String dOu;
    protected String dOw;
    protected int ciR;
    
    public AreaEffectBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int vU()
    {
        return this.aZD;
    }
    
    public int bDO()
    {
        return this.fXZ;
    }
    
    public int bDP()
    {
        return this.fss;
    }
    
    public int bDQ()
    {
        return this.fYa;
    }
    
    public boolean bDR()
    {
        return this.fYb;
    }
    
    public boolean bDS()
    {
        return this.fYc;
    }
    
    public boolean bDT()
    {
        return this.fYd;
    }
    
    public boolean bDU()
    {
        return this.fYe;
    }
    
    public boolean bDV()
    {
        return this.fYf;
    }
    
    public String getType()
    {
        return this.Vq;
    }
    
    public int[] bDW()
    {
        return this.fYg;
    }
    
    public int[] bDX()
    {
        return this.fYh;
    }
    
    public int[] bDY()
    {
        return this.fYi;
    }
    
    public int[] bDZ()
    {
        return this.fYj;
    }
    
    public float[] bEa()
    {
        return this.fYk;
    }
    
    public float[] Bc()
    {
        return this.biV;
    }
    
    public int[] Ds()
    {
        return this.blY;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public String bEb()
    {
        return this.fYl;
    }
    
    public String bEc()
    {
        return this.fYm;
    }
    
    public String bEd()
    {
        return this.dOu;
    }
    
    public String bEe()
    {
        return this.dOw;
    }
    
    public int Sr()
    {
        return this.ciR;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aZD = 0;
        this.fXZ = 0;
        this.fss = 0;
        this.fYa = 0;
        this.fYb = false;
        this.fYc = false;
        this.fYd = false;
        this.fYe = false;
        this.fYf = false;
        this.Vq = null;
        this.fYg = null;
        this.fYh = null;
        this.fYi = null;
        this.fYj = null;
        this.fYk = null;
        this.biV = null;
        this.blY = null;
        this.bav = null;
        this.fYl = null;
        this.fYm = null;
        this.dOu = null;
        this.dOw = null;
        this.ciR = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.aZD = a.getInt();
        this.fXZ = a.getInt();
        this.fss = a.getInt();
        this.fYa = a.getInt();
        this.fYb = a.readBoolean();
        this.fYc = a.readBoolean();
        this.fYd = a.readBoolean();
        this.fYe = a.readBoolean();
        this.fYf = a.readBoolean();
        this.Vq = a.clg().intern();
        this.fYg = a.cli();
        this.fYh = a.cli();
        this.fYi = a.cli();
        this.fYj = a.cli();
        this.fYk = a.clk();
        this.biV = a.clk();
        this.blY = a.cli();
        this.bav = a.cli();
        this.fYl = a.clg().intern();
        this.fYm = a.clg().intern();
        this.dOu = a.clg().intern();
        this.dOw = a.clg().intern();
        this.ciR = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eDt.getId();
    }
}