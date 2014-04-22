package com.ankamagames.wakfu.client.binaryStorage;

public class AvatarBreedBinaryData implements dEZ {
    protected int az;
    protected String m_name;
    protected int bTm;
    protected int bTn;
    protected int bTo;
    protected int bTp;
    protected int bTq;
    protected int bTr;
    protected int bTs;
    protected int bTt;
    protected int bTu;
    protected int bTv;
    protected int bTw;
    protected int bTx;
    protected int bTy;
    protected int bTz;
    protected int bTA;
    protected byte[] bTB;
    protected float[] bTC;
    
    public AvatarBreedBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public String getName()
    {
        return this.m_name;
    }
    
    public int Pu()
    {
        return this.bTm;
    }
    
    public int Pv()
    {
        return this.bTn;
    }
    
    public int Pw()
    {
        return this.bTo;
    }
    
    public int Px()
    {
        return this.bTp;
    }
    
    public int Py()
    {
        return this.bTq;
    }
    
    public int Pz()
    {
        return this.bTr;
    }
    
    public int PA()
    {
        return this.bTs;
    }
    
    public int PB()
    {
        return this.bTt;
    }
    
    public int PC()
    {
        return this.bTu;
    }
    
    public int PD()
    {
        return this.bTv;
    }
    
    public int PE()
    {
        return this.bTw;
    }
    
    public int PF()
    {
        return this.bTx;
    }
    
    public int PG()
    {
        return this.bTy;
    }
    
    public int PH()
    {
        return this.bTz;
    }
    
    public int PI()
    {
        return this.bTA;
    }
    
    public byte[] PJ()
    {
        return this.bTB;
    }
    
    public float[] PK()
    {
        return this.bTC;
    }
    
    public void reset()
    {
        this.az = 0;
        this.m_name = null;
        this.bTm = 0;
        this.bTn = 0;
        this.bTo = 0;
        this.bTp = 0;
        this.bTq = 0;
        this.bTr = 0;
        this.bTs = 0;
        this.bTt = 0;
        this.bTu = 0;
        this.bTv = 0;
        this.bTw = 0;
        this.bTx = 0;
        this.bTy = 0;
        this.bTz = 0;
        this.bTA = 0;
        this.bTB = null;
        this.bTC = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.m_name = a.clg().intern();
        this.bTm = a.getInt();
        this.bTn = a.getInt();
        this.bTo = a.getInt();
        this.bTp = a.getInt();
        this.bTq = a.getInt();
        this.bTr = a.getInt();
        this.bTs = a.getInt();
        this.bTt = a.getInt();
        this.bTu = a.getInt();
        this.bTv = a.getInt();
        this.bTw = a.getInt();
        this.bTx = a.getInt();
        this.bTy = a.getInt();
        this.bTz = a.getInt();
        this.bTA = a.getInt();
        this.bTB = a.clh();
        this.bTC = a.clk();
    }
    
    final public int gZ()
    {
        return aPw.eEX.getId();
    }
}